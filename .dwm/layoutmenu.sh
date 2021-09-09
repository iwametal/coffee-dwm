#!/bin/sh

cat <<EOF | xmenu
|M| centeredmaster            11
>M> centeredfloatMaster       12
[]= tile                      0
TTT bstack                    4
[@] spiral                    2
[\\ dwindle                   3
[M] monocle                   1
H[] deck                      5
=== bstackhoriz               6 
HHH grid                      7
GNG nrowgrid                  8 
--- horizgrid                 9 
::: gaplessgrid               10
><> floating                  13
EOF
