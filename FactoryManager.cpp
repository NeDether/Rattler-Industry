#include "stdafx.h"
#include "FactoryManager.h"
#include "DrillBuilding.h"
#include "Spore/Simulator/cInteractableObject.h"
/// AUTOGENERATED METHODS ///
using namespace Simulator;
int FactoryManager::AddRef() {
	return Simulator::cStrategy::AddRef();
}
int FactoryManager::Release() {
	return Simulator::cStrategy::Release();
}

const char* FactoryManager::GetName() const {
	return "RattlerSpore::FactoryManager";
}

bool FactoryManager::Write(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Write(stream);
}
bool FactoryManager::WriteToXML(Simulator::XmlSerializer* writexml)
{
	return false;
}
bool FactoryManager::Read(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Read(stream);
}

/// END OF AUTOGENERATED METHODS ///
////////////////////////////////////

Simulator::Attribute FactoryManager::ATTRIBUTES[] = {
	// Add more attributes here
	// This one must always be at the end
	//SimAttribute(tGameDataVectorT<DrillBuilding>,FactorySave,1),
	Simulator::Attribute()
};

void FactoryManager::Initialize() {
	sInstance = this;
	
}

void FactoryManager::Dispose() {
	
}

void FactoryManager::Update(int deltaTime, int deltaGameTime) {

	if (GetCurrentContext() == SpaceContext::Planet) {
		if (!LoadPlanet) {
			uint32_t pid = GetActivePlanetRecord()->GetID().internalValue;
			auto buildings = GetData<DrillBuilding>();
			for (auto fact : buildings) {
				if (fact->getPlanetID() == pid) {

					App::ConsolePrintF("Loaded a Factory");

					fact->render();
					

				
				}
				LoadPlanet = true;
				
			}
		}
	}
	else {
		LoadPlanet = false;
	
	}
	

	
}

FactoryManager* FactoryManager::Get()
{
	return sInstance;
}

bool FactoryManager::CreateBuilding(const Vector3& position, uint32_t buildingType)
{
	const PlanetID mario = GetActivePlanetRecord()->GetID();
	uint32_t greg = mario.internalValue;
	auto factory = simulator_new<DrillBuilding>();
	factory->init(position, greg);
	return false;
}

FactoryManager* FactoryManager::sInstance;