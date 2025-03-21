#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Bowtie2Plugin.h"

void Bowtie2Plugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 std::cout << file << std::endl;
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   if (key.length() == 0) break;
   ifile >> value;
   if (value.length() == 0) break;
   parameters[key] = value;
 }

}

void Bowtie2Plugin::run() {}

void Bowtie2Plugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "bowtie2";
myCommand += " ";
myCommand += "-x";
myCommand += " ";
myCommand += std::string(PluginManager::prefix())+parameters["db"];
myCommand += " ";
if (parameters.count("sequences") != 0) {
myCommand += "-U";
myCommand += " ";
myCommand += std::string(PluginManager::prefix())+parameters["sequences"] + " ";
}
else {
myCommand += "-q -1";
myCommand += " ";
myCommand += std::string(PluginManager::prefix())+parameters["sequences1"] + " ";
myCommand += "-2";
myCommand += " ";
myCommand += std::string(PluginManager::prefix())+parameters["sequences2"] + " ";
}
if (parameters.count("threads") != 0) {
myCommand += "--threads";
myCommand += " ";
myCommand += parameters["threads"] + " ";
}

if (parameters.count("endtoend") != 0 && parameters["endtoend"] == "True") {
	myCommand += "--end-to-end ";
}
if (parameters.count("all") != 0 && parameters["all"] == "True") {
	myCommand += "-a ";
}
if (parameters.count("filetype") != 0 && parameters["filetype"] == "FASTA") {
	myCommand += "-f ";
}
if (parameters.count("seedsubstr") != 0) {
	myCommand += "-L "+parameters["seedsubstr"]+" ";
}
if (parameters.count("maxpenalty") != 0) {
	myCommand += "--mp "+parameters["maxpenalty"]+" ";
}
if (parameters.count("nonpenalty") != 0) {
	myCommand += "--np "+parameters["nonpenalty"]+" ";
}
if (parameters.count("readgapopen") != 0) {
	myCommand += "--rdg "+parameters["readgapopen"]+" ";
}
if (parameters.count("refgapopen") != 0) {
	myCommand += "--rfg "+parameters["refgapopen"]+" ";
}
if (parameters.count("scoremin") != 0) {
	myCommand += "--score-min "+parameters["scoremin"]+" ";
}
if (parameters.count("atleast") != 0) {
	myCommand += "--al "+std::string(PluginManager::prefix())+parameters["atleast"]+" ";
}
if (parameters.count("giveup") != 0) {
	myCommand += "-D "+parameters["giveup"]+" ";
}
if (parameters.count("repeat") != 0) {
	myCommand += "-R "+parameters["repeat"]+" ";
}
if (parameters.count("mismatch") != 0) {
	myCommand += "-N "+parameters["mismatch"]+" ";
}
if (parameters.count("length") != 0) {
	myCommand += "-L "+parameters["length"]+" ";
}
if (parameters.count("interval") != 0) {
	myCommand += "-i "+parameters["interval"]+" ";
}
if (parameters.count("local") != 0 && parameters["local"] == "True") {
	myCommand += "--local ";
}
if (parameters.count("processors")) {
	myCommand += "-p "+parameters["processors"]+" ";
}
if (parameters.count("veryfastlocal") != 0 && parameters["veryfastlocal"] == "True") {
	myCommand += "--very-fast-local ";
}
if (parameters.count("nodiscordant") != 0 && parameters["nodiscordant"] == "True") {
	myCommand += "--no-discordant ";
}
if (parameters.count("verysensitive") != 0 && parameters["verysensitive"] == "True") {
	myCommand += "--very-sensitive ";
}
if (parameters.count("nomixed") != 0 && parameters["nomixed"] == "True") {
	myCommand += "--no-mixed ";
}
if (parameters.count("nounal") != 0 && parameters["nounal"] == "True") {
	myCommand += "--no-unal ";
}
if (parameters.count("reorder") != 0 && parameters["reorder"] == "True") {
	myCommand += "--reorder ";
}
myCommand += "-S";
myCommand += " ";
myCommand += outputfile+".sam";
//myCommand += " ";
//myCommand += "1>"+outputfile+".sam0.bowtie2.out 2>"+outputfile+".sam0.bowtie2.err";
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<Bowtie2Plugin> Bowtie2PluginProxy = PluginProxy<Bowtie2Plugin>("Bowtie2", PluginManager::getInstance());
