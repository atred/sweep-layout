```
./link.sh <path-to-qmk_firmware>
qmk setup

qmk flash -e CONVERT_TO=kb2040 -kb ferris/sweep -km atred -bl uf2-split-left
qmk flash -e CONVERT_TO=kb2040 -kb ferris/sweep -km atred -bl uf2-split-right
```
