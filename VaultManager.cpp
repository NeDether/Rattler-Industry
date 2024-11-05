#include "stdafx.h"
#include "VaultManager.h"

/// AUTOGENERATED METHODS ///

int VaultManager::AddRef() {
	return Simulator::cStrategy::AddRef();
}
int VaultManager::Release() {
	return Simulator::cStrategy::Release();
}

const char* VaultManager::GetName() const {
	return "RattlerSpore::VaultManager";
}

bool VaultManager::Write(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Write(stream);
}
bool VaultManager::WriteToXML(Simulator::XmlSerializer* writexml)
{
	return false;
}
bool VaultManager::Read(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Read(stream);
}

/// END OF AUTOGENERATED METHODS ///
////////////////////////////////////

using namespace Simulator;

Simulator::Attribute VaultManager::ATTRIBUTES[] = {
	// Add more attributes here
	// This one must always be at the end
	Simulator::Attribute()
};

void VaultManager::Initialize() {
	App::ConsolePrintF("SKIBIDI");
	cutsceneSeti = false;
	sInstance = this;
}

	
void VaultManager::Dispose() {
	
}

void VaultManager::Update(int deltaTime, int deltaGameTime) {
	
}



bool VaultManager::GenerateVault(cStarRecordPtr StrRecord)
{	//If black hole, or galactic object end.
	if ((int)StrRecord->GetType() <= 3) {
		App::ConsolePrintF("The system is a black hole.");
		return false;
	}
	if (GetCurrentContext() != SpaceContext::Galaxy) {
	
		return false;
	}
	if (StrRecord->GetTechLevel() == TechLevel::Creature) {
		int i = 0;
		bool generatedVault = false;
		//set to 10 normally
		int chmance = rand(12);
		if (chmance > 1) {
			return false;
		}
		//seriously replace with for each it keeps crashing
		while (!generatedVault || (i <= StrRecord->mPlanetCount-1)) {
			//replace with foreach
			if (StrRecord->GetPlanetRecord(i) == nullptr) {
				return false;
			}
			int rando = rand(14);
			App::ConsolePrintF("rand %d", rando);
			App::ConsolePrintF("rand 2 %d", rando);
			int pType = (int)StrRecord->GetPlanetRecord(i)->mType;
			
			//If T0 T1 T2 or T3 then generate vault, otherwise if gas giant or asteroid belt, skip.
			if(pType >= 2 && pType <= 5) {
				//If statement was here that checked the boolean, however it resulted in returning a nullptr and crashes the game.
				
				if (!VaultManagerA.cutsceneSeti) {
					CinematicManager.PlayCinematic("RSPORE_VAULTSETIWAIT", 0, 0, 0, 0, 0);
					VaultManagerA.cutsceneSeti = true;
				}

				


				auto vaultplanet = StrRecord->GetPlanetRecord(i)->GetID();
				//replace with hash_map
				ResourceKey vpkey;
				vpkey.instanceID = vaultplanet.internalValue;
				vaultplanets.emplace(vpkey,vaultplanet);
				ResourceKey vaultScript;
				//rattlesnake //prop //planetTerrainScripts_artDirected~
				//vaultScript = ResourceKey(0x98eeb4f9, 0x00B1B104, 0x4184a200);
				//vaultTEST //prop //planetTerrainScriptsRSPORE
				vaultScript = ResourceKey(0xa395f2a9, 0x00B1B104, 0x8C2C3803);
				StrRecord->GetPlanetRecord(i)->SetGeneratedTerrainKey(vaultScript);
				StrRecord->GetPlanetRecord(i)->mCommodityNodes.clear();
				//StrRecord->GetPlanetRecord(i)->mFlags = 17480;
				//StrRecord->GetPlanetRecord(i)->mType = PlanetType::T1;

				//StrRecord->GetPlanetRecord(i)->mSpiceGen = ResourceKey({ id(""),0,0 });

				App::ConsolePrintF("A vault has generated on planet %d", i);
				return true;
				
			}
			i++;
		
		}
	}
	App::ConsolePrintF("The system has the incorrect tech level.");
	return false;
}

VaultManager* VaultManager::Get()
{
	return sInstance;
}
bool VaultManager::isVaultPlanet(uint32_t PlanetID)
{	//Get rid of the simulator system, a regular vector would be more optimized.
	
	//		SavedBuildings.clear();

	if (vaultplanets.find(ResourceKey().WithInstance(PlanetID)) != vaultplanets.end()) {

		return true;


	}
	return false;
}

bool VaultManager::isGrobPlanet(uint32_t pID)
{
	if (PlanetID(pID).GetRecord()->GetStarRecord()->mEmpireID == StarManager.GetGrobEmpireID() && PlanetID(pID).GetRecord()->GetTechLevel() == TechLevel::Empire) {
		return true;
	}
	return false;
}

bool VaultManager::isSkondPlanet(uint32_t pID)
{
	if (PlanetID(pID).GetRecord()->GetTechLevel() == TechLevel::City) {
		return true;
	}
	return false;
}

VaultManager* VaultManager::sInstance;