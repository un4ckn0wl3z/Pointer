#pragma once
// Generated using ReClass 2016
class MainClass;
class Class1;
class Class2;

class MainClass
{
public:
	char pad_0x0000[0x8]; //0x0000
	Class1* class1; //0x0008 
	char pad_0x000C[0x34]; //0x000C


}; //Size=0x0040

class Class1
{
public:
	char pad_0x0000[0x4]; //0x0000
	Class2* class2; //0x0004 
	char pad_0x0008[0x3FC]; //0x0008

}; //Size=0x0404

class Class2
{
public:
	char pad_0x0000[0x8]; //0x0000
	int primayAmmo; //0x0008 
	char pad_0x000C[0x3F8]; //0x000C

}; //Size=0x0404

