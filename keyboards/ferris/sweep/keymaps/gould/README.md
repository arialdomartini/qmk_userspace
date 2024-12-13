# Keyboard
This is the keymap for the 1st Crab Broom (Ferris Sweep) I built.

# Build

- Covertion is needed because of the RP2020 used by the build, which
uses UF2 bootloader instead of DFU.

```bash
qmk compile -e CONVERT_TO=promicro_rp2040 -kb ferris/sweep -km gould 
```

This generates a `uf2` file.

- Connect the keyboard and click the reset button twice (really
  quickly).
  
- The MCU will be mounted as an external disk.

- Copy the `uf2` file. It should restart automatically.
