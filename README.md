# CY-Bunker

Developed by ABAJOU Sofyane, EL JARJINI Hicham, and JAMHOUR Nassim. 
Original subject: [C-WIRE](documents/subject.pdf) <br>
Project report: [PDF](documents/report.pdf) <br>

## Instructions

1. **Before Installing**
   - Make sure to use Linux or to have downloaded a Linux terminal.

2. **Running the Project**
   - Execute the project with the following command:
     ```sh
     ./c-wire.sh <CSV File> <Station Type> <Consumer Type> [Power Plant ID]
     ```
   - Example:
     ```sh
     ./c-wire.sh data.csv hvb comp 1
     ```

3. **Options**
   - `<CSV File>`: Path to the CSV file.
   - `<Station Type>`: Type of station (`hva`, `hvb`, `lv`).
   - `<Consumer Type>`: Type of consumer (`comp`, `indiv`, `all`). Note: `comp` only works with `hva` or `hvb` station types.
   - `[Power Plant ID]`: (Optional) ID of the power plant, must be a positive number.

4. **Help Manual**
   - To display the help manual, use the `-h` option:
     ```sh
     ./c-wire.sh -h
     ```

5. **Cleaning Up**
   - To delete object files and the executable, use the command:
     ```sh
     make clean -C codeC
     ```

## Contributors

<a href="https://github.com/nassimjmh/CY-Bunker/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=nassimjmh/CY-Bunker" />
</a>