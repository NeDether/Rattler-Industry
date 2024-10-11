#include "stdafx.h"
#include "VaultPlanet.h"

/// AUTOGENERATED METHODS ///

size_t VaultPlanetFactory::GetTypes(uint32_t* pDstTypes, size_t count) const {
	if (count >= 1) {
		pDstTypes[0] = VaultPlanet::NOUN_ID;
		return 1;
	}
	return 0;
}
Object* VaultPlanetFactory::Create(uint32_t type, ICoreAllocator* pAllocator) {
	return new VaultPlanet();
}
const char* VaultPlanetFactory::GetName(uint32_t type) const {
	return "VaultPlanet";
}


VaultPlanet::VaultPlanet(uint32_t pID)
{	
	init(pID);
}

VaultPlanet::VaultPlanet()
{
	init(0);
}

VaultPlanet::~VaultPlanet()
{
}

int VaultPlanet::AddRef() {
	return DefaultRefCounted::AddRef();
}
int VaultPlanet::Release() {
	return DefaultRefCounted::Release();
}

uint32_t VaultPlanet::GetCastID() const {
	return TYPE;
}
uint32_t VaultPlanet::GetNounID() const {
	return NOUN_ID;
}

void* VaultPlanet::Cast(uint32_t type) const {
	CLASS_CAST(VaultPlanet);
	PARENT_CAST(cGameData);
	return nullptr;
}

bool VaultPlanet::Write(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Write(stream);
}
bool VaultPlanet::WriteToXML(Simulator::XmlSerializer* writexml)
{
	return false;
}
bool VaultPlanet::Read(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Read(stream);
}

void VaultPlanet::init(uint32_t pid)
{
	looted = false;
	scanned = false;
	planetOn = pid;

}

uint32_t VaultPlanet::GetPlanetID()
{
	return planetOn;
}


/// END OF AUTOGENERATED METHODS ///
////////////////////////////////////

Simulator::Attribute VaultPlanet::ATTRIBUTES[] = {
	// Add more attributes here
	// This one must always be at the end
	Simulator::Attribute()
};