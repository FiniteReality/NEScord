# Serial communication #

See [1] for information on the expansion port on the NES

## Used pins ##

06,07,08,09,10,38,39,40,41,42

## Pin descriptions ##

- **EXP9**: SOCK READ
- **EXP8**: SOCK WRITE
- **EXP7**: CLOCK
- **EXP6**: DATA 0
- **EXP5**: DATA 1
- **EXP4**: DATA 2
- **EXP3**: DATA 3
- **EXP2**: DATA 4
- **EXP1**: ACK
- **EXP0**: HELLO

## Explanation ##

### SOCK READ ###

When this pin is high, the CPU is ready to receive data from the connection.

### SOCK WRITE ###

When this pin is high, the CPU is ready to write data to the connection. 

### CLOCK ###

This pin maintains the clock between the connection. Every time it is pulsed,
data should be written when SOCK READ/WRITE is high.

### DATA n ###

A single bit of data

### HELLO ###

Used for probing whether a client is connected.

### ACK ###

Used as a general acknowledgement for reads/writes

## Protocol examples ##

*C*: The hardware *attached* to the NES
*S*: The NES itself

*pulse*: This signal is raised/lowered in sync with `CLOCK`.
*high*: This signal is raised until it is lowered again.
*low:* This signal is lowered until it is raised or pulsed again.

Every message is sent on a pulse of `CLOCK`.

Whenever the client does not acknowledge a request, the server *must* assume
that the connection is dead.

### Handshake ###

```text
S->C HELLO pulse # probe the client
C->S HELLO pulse # acknowledgement
```

Now the connection is established, the server may issue `SOCK READ` or
`SOCK WRITE`.

If the client does not respond with a HELLO pulse, the server *must* assume
that there is no client connected.

### Read request ###

```text
S->C SOCK READ high # request to read
C->S ACK pulse # acknowledge the request

C->S DATA 1-4 pulse
...

S->C SOCK READ low # buffer full, stop sending data
C->S ACK pulse # acknowledge the message
```

### Write request ###

```text
S->C SOCK WRITE high # request to write
C->S ACK pulse # acknowledge the request

S->C DATA 1-4 pulse
...

S->C SOCK WRITE low # buffer emptied, stop reading data
C->S ACK pulse # acknowledge the request
```

### CLOCK ###

The `CLOCK` bit is pulsed by the server at a variable rate decided by the
server. Clients must not assume that it is constant, and must assume that it
may not be pulsed for long periods of time. This is to improve efficiency so
that the server does not have to spend CPU cycles maintaining the clock when
it needs to spend its time doing something else.

[1]: http://wiki.nesdev.com/w/index.php/NES_expansion_port_pinout
