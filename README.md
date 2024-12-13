# CY-Bunker ⚡

Developed by ABAJOU Sofyane, EL JARJINI Hicham, and JAMHOUR Nassim. 
Original subject: [C-WIRE](documents/subject.pdf) 📄<br>
Project report: [PDF](documents/report.pdf) 📑<br>

## 📋 Instructions
0. **🔧 Before Installing**
  - Make sure to use Linux or to have downloaded a Linux terminal. <br>
    <a href="https://www.youtube.com/watch?v=Hwbii-fnKIk">
     <img src="https://go-skill-icons.vercel.app/api/icons?i=linux,wsl" alt="Linux"/>
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
   - `<Consumer Type>`: Type of consumer (`comp`, `indiv`, `all`). Note: `comp` only works with `hva` or `hvb` station types.
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


## 🌐 Made using

<a href="https://github.com/nassimjmh/CY-Bunker">
    <img src="https://skillicons.dev/icons?i=c,bash,vscode&theme=dark" alt="Made using" style="vertical-align: middle; margin-right: 10px;"/>
</a>
<a href="https://github.com/nassimjmh/CY-Bunker">
    <img src="https://cdn.discordapp.com/attachments/838699933586423821/1317252655990575174/removed.png?ex=675e02a2&is=675cb122&hm=4689bc9399809aee58bfc1afb87e12694e691e4908f629916499c1fd89ec3bcc&" alt="Made using" width="66" style="vertical-align: middle; margin-right: 10px; margin-bottom: -5px;"/>
</a>
<a href="https://github.com/nassimjmh/CY-Bunker">
    <img src="https://skillicons.dev/icons?i=git,github&theme=dark" alt="Made using" style="vertical-align: middle; margin-left: -4px;"/>
</a>


## 👥 Contributors

<a href="https://github.com/nassimjmh/CY-Bunker/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=nassimjmh/CY-Bunker" alt="Contributors" />
</a>