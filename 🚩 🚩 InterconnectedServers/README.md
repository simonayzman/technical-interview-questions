### Interconnected servers

Given an interconnected cluster of computers, design a system where a single script can be deployed
to a single origin machine that must then communicate (to itself and) to all of the other machines
that that script needs to be executed.

Modification 1: Multiple different scripts can be deployed to different origin machines and need to
communicate execution.

Modification 2: A single script might need to be run multiple times, but the instruction is given at
different times and the same script might be deployed to different origin machines during each request.

\[[Solution](solution.cpp)\]
