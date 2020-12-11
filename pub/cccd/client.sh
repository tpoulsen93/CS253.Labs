#!/bin/bash

Open()  { exec {fd}<>/dev/tcp/localhost/$(<port) ; }
Close() { exec {fd}<&- ; }

Open
{
    echo single
    # echo thread
    # echo process

    echo add vowel ^aeiou
    echo add consonants bcdfghjklmnpqrstvwxyz
    echo add letters ^a-z
    echo add digits 0-9
    
    echo txt .
    echo -e "Hello\n123\nworld!"
    # cat ../txt/Alice-in-Wonderland.txt
    echo .
} >&$fd
cat <&$fd
Close

Open
echo exit >&$fd
Close

