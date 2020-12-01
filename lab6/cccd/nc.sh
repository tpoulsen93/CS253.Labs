#!/bin/bash

exec socat - TCP4:localhost:$((UID+234))
