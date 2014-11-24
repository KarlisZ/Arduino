<?xml version="1.0" encoding="UTF-8"?>
<session version="3.2.2">
 <item name="license"></item>
 <group name="locked"/>
 <group name="settings">
  <item name="tabs">1</item>
  <item name="windows">0</item>
  <item name="grid">3</item>
 </group>
 <group name="windows"/>
 <group name="search">
  <item name="options">4129280</item>
  <item name="replace">0</item>
 </group>
 <group name="vars">
  <item id="PROJECT">blinky</item>
  <item id="ARDUINO_HOME">C:\Program Files (x86)\Arduino</item>
  <item id="ARDUINO_SKETCHBOOK">C:\Users\Miro\Documents\Arduino</item>
  <item id="BOARD_MCU">atmega328p</item>
  <item id="BOARD_VARIANT">standard</item>
  <item id="BOARD_F_MHZ">16</item>
  <item id="BOARD_COM">COM5</item>
  <item id="BOARD_BAUD">115200</item>
 </group>
 <group name="tools">
  <group name="tool">
   <item name="icon">3</item>
   <item name="title">build</item>
   <item name="command">&quot;%ARDUINO_SKETCHBOOK%\tools\utils\tclsh.exe&quot;</item>
   <item name="args">&quot;%ARDUINO_SKETCHBOOK%\tools\scripts\build_avr.tcl&quot; %PROJECT% &quot;qp_avr&quot;</item>
   <item name="initial">.</item>
   <item name="options">3</item>
  </group>
  <group name="tool">
   <item name="icon">5</item>
   <item name="title">clean</item>
   <item name="command">&quot;%ARDUINO_SKETCHBOOK%\tools\utils\rm.exe&quot;</item>
   <item name="args">bin\*</item>
   <item name="initial">.</item>
   <item name="options">2</item>
  </group>
  <group name="tool">
   <item name="icon">6</item>
   <item name="title">upload</item>
   <item name="command">&quot;%ARDUINO_SKETCHBOOK%\tools\scripts\upload_avr.bat&quot;</item>
   <item name="args">%PROJECT%</item>
   <item name="initial">.</item>
   <item name="options">2</item>
  </group>
  <group name="tool">
   <item name="icon">8</item>
   <item name="title">teraterm</item>
   <item name="command">C:\tools\teraterm-4.77\ttermpro.exe</item>
   <item name="args">/%BOARD_COM% /%BOARD_BAUD%</item>
   <item name="initial"></item>
   <item name="options">4</item>
  </group>
  <group name="tool">
   <item name="icon">5</item>
   <item name="title">clean all</item>
   <item name="command">&quot;%ARDUINO_SKETCHBOOK%\tools\utils\rm.exe&quot;</item>
   <item name="args">bin\* lib\*</item>
   <item name="initial"></item>
   <item name="options">2</item>
  </group>
 </group>
</session>
