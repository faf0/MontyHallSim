MontyHallSim
============

This program simulates the Monty Hall problem:

  http://en.wikipedia.org/wiki/Monty_Hall_problem

The setting of the Monty Hall problem is a game show.
In that show, a single player wants to win a car
that is hidden behind one of three doors.
Behind the other two doors, there are goats.

First, the player picks one of the three doors.
Second, the host who knows what is behind the doors,
opens one of the two doors which the player had not
picked in order to show him the goat behind that door.
Third, the host allows the player to either continue with
his initial choice or to switch to the other closed door.

The player will win with probability 2/3, if he decides
to switch.
If the player does not switch, he will lose with
probability 2/3.

This program simulates the above situation. It is written
in C and uses only standard libraries.

How To Run
----------

Go to the directory containing the Makefile in a shell
and run `make`.

Examples
--------

The player plays 100 times without switching:

	./monty_hall_sim 0 100
	Number of games: 100. The player won 38 times and lost 62 times.
	Success rate: 0.380000

The player plays 100 times and switches every time:

	./monty_hall_sim 1 100
	Number of games: 100. The player won 70 times and lost 30 times.
	Success rate: 0.700000

Copyright
---------

Copyright 2013 Fabian Foerg

