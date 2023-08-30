#ifndef BOWTIE2PLUGIN_H
#define BOWTIE2PLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class Bowtie2Plugin : public Plugin
{
public: 
 std::string toString() {return "Bowtie2";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
std::map<std::string, std::string> parameters;
};

#endif
