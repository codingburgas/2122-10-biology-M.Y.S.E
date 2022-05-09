<p align = "center">
    <img src="project-biology/src/logo.png" width = 500 >
</p>

<div align = "center">
    <img src = "https://img.shields.io/github/languages/count/codingburgas/2122-10-biology-M.Y.S.E?style=for-the-badge">
    <img src = "https://img.shields.io/github/contributors/codingburgas/2122-10-biology-M.Y.S.E?style=for-the-badge">
    <img src = "https://img.shields.io/github/repo-size/codingburgas/2122-10-biology-M.Y.S.E?style=for-the-badge">
  <img src = "https://img.shields.io/github/last-commit/codingburgas/2122-10-biology-M.Y.S.E?style=for-the-badge">
</div>

## 📝Table of contents
- [Description](#description)
- [Built Using](#built_using)
- [Authors](#authors)
- [Presentation and Documentation](#documentation)
- [How to set up Project](#set_up)   
- [Interface](interface)

## 📖 Description <a name = "description"></a>
This is a C++ project, made for a school project. It's main goal is to teach people how a small ecosystem works and how the different types of animals are connected with one another.

## 💻 Build Using <a name="built_using"></a>
- [Visual Studio](https://visualstudio.microsoft.com/) - Application
- [TGUI](https://tgui.eu/) - Framework
- [Word](https://www.microsoft.com/en-us/microsoft-365/word) - Documentation
- [PowerPoint](https://www.microsoft.com/en-us/microsoft-365/powerpoint) - Presentation
- [Excel](https://www.microsoft.com/en-us/microsoft-365/excel) - QA Documentation

## 👥 Authors <a name="authors"></a>
- [Stas Uzunov](https://github.com/SSUzunov19) - Scrum Trainer 
- [Daniel Georgiev](https://github.com/DZGeorgiev19) - Front-End Developer
- [Vasil Mladenov](https://github.com/VLMladenov19) - Back-End Developer
- [Viktor Kirov](https://github.com/VRKirov19) - QA Engineer

## 📋 Presentation and Documentation <a name="documentation"></a>
+ <a href = "https://codingburgas-my.sharepoint.com/:w:/g/personal/vlmladenov19_codingburgas_bg/EQ9pBv58_KZFlYmRgcnzeG8BoKyq7DFhj6IqH-V_cNrCQA?e=1L9PHO">Documentation</a>
+ <a href = "https://codingburgas-my.sharepoint.com/:p:/g/personal/vlmladenov19_codingburgas_bg/EWDQwVTjrwZPst6mDR1JLxIBPNWBcML3ReJ1F2XE0PsZ2g?e=l1jPOq">Presentation</a>
+ <a href = "https://codingburgas-my.sharepoint.com/:x:/g/personal/vlmladenov19_codingburgas_bg/EVW6aeq0eqtOqdmL3zHF0u4BE_aZrdrRtKRhO8NDQ95YIg?e=ZxVUZf">QA Documentation</a>

## ⚙️ How to set up Project <a name="set_up"></a>
- Download the program from the green button or clone it by using this command:
<pre>git clone https://github.com/codingburgas/2122-10-biology-M.Y.S.E.git</pre>
- Follow this link, to install SMFL - <a href="https://github.com/SFML/SFML">Here</a> 
- Follow this link, to install TGUI Nightly build - <a href="https://github.com/texus/TGUI">Here</a>
- Download SFML and TGUI in the directory where you have downloaded your program
- Rename **TGUI-0.10-nightly** to **TGUI-0.10**
<img src = "https://cdn.discordapp.com/attachments/958758286902063155/972956081288536114/unknown.png" width = 600>
- Open the project, to the **project-biology** folder and open the solution file
- Right click **project-biology** 
- Go to **Properties->Configuration Properties->Debugging->Environment** and type:
<pre>PATH=$(SolutionDir)..\..\\TGUI-0.10\\\bin;$(SolutionDir)..\..\SFML-2.5.1\bin</pre>
<img src = "https://cdn.discordapp.com/attachments/958758286902063155/972956618234933298/unknown.png" width = 600>

- Change the solution platform to **x86**
- Now you can run the project

## 🖼️ Interface of Project <a name="interface"></a>
- Тhis is the main menu where you choose what to do:
     * Play - Open the simulation
     * About Us - Information about the creators of the project
     * Help - Shows information about the simulation and how to operate it                   
     * Quit - Еxit the program

    <div align="center">
    <br>                                 
    <img src="https://cdn.discordapp.com/attachments/958758286902063159/972941932282126367/unknown.png" width=600>
    <br>
    <h1>  Simulation Tab  </h1>
    <br> 
    <img src="https://cdn.discordapp.com/attachments/958758286902063159/972941730687107103/unknown.png" width=600>
    <br>
    <h1> About Us Tab </h1>
    <br>
    <img src= "https://cdn.discordapp.com/attachments/958758286902063159/972950033861320704/about-us.png" width=600>
    <br>
    <h1> Help Tab </h1>
    <br>
    <img src= "https://cdn.discordapp.com/attachments/958758286902063159/972951761331585064/unknown.png" width=600>
    <br>
    </div>