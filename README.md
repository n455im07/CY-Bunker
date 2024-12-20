# CY-Bunker ⚡

CY-Bunker is a engineering project developed by ABAJOU Sofyane, EL JARJINI Hicham, and JAMHOUR Nassim. (Year 2024) 
Original subject: [C-WIRE](documents/subject.pdf) 📄<br>
Project report: [PDF](documents/report.pdf) 📑<br>

## 📋 Instructions
0. **🔧 Before Installing**
  - Make sure to use Linux or to have downloaded a Linux terminal. <br>
    <a href="https://www.youtube.com/watch?v=Hwbii-fnKIk">
     <img src="https://go-skill-icons.vercel.app/api/icons?i=linux,wsl,debian,ubuntu" alt="Linux"/>
    </a>



1. **🚀 Running the Project**
   - Execute the project with the following command:
     ```sh
     ./c-wire.sh <CSV File> <Station Type> <Consumer Type> [Power Plant ID]
     ```
   - If you don't have execute permissions, you can run the script with:
     ```sh
     bash c-wire.sh <CSV File> <Station Type> <Consumer Type> [Power Plant ID]
     ```
   - Example:
     ```sh
     ./c-wire.sh data.csv hvb comp 1
     ```

2. **⚙️ Options**
   - `<CSV File>`: Path to the CSV file.
   - `<Station Type>`: Type of station (`hva`, `hvb`, `lv`).
   - `<Consumer Type>`: Type of consumer (`comp`, `indiv`, `all`). Note: `hva` and `hvb` stations only works with `comp` consumers.
   - `[Power Plant ID]`: (Optional) ID of the power plant, must be a positive number.

3. **❓ Help Manual**
   - To display the help manual, use the `-h` option:
     ```sh
     ./c-wire.sh -h
     ```

4. **🧹 Cleaning Up**
   - To delete object files and the executable, use the command:
     ```sh
     make clean -C codeC
     ```

## 📦 Dependencies
Before running the project, make sure you have the following installed:
- **GCC** for compiling C code
- **Make** for building the project

To install the necessary dependencies on Debian/Ubuntu-based systems, run:
```bash
sudo apt update
sudo apt install build-essential
```

## 🌐 Made using

<a href="https://github.com/nassimjmh/CY-Bunker">
    <img src="https://skillicons.dev/icons?i=c,bash,vscode,git,github&theme=dark" alt="Made using"/>
</a>


## 👥 Collaborators

<a href="https://github.com/nassimjmh/CY-Bunker/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=nassimjmh/CY-Bunker" alt="Contributors" />
</a>

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
