#include "miscfunc.h"
#include "dirent.h"
#include "fighter.h"
#include "characterobserver.h"
#include "itemsSaving.h"
#include "Save.h"
#include <iostream>
#include "Load.h"
#include <ctime>
#include "Elemental.h"
#include "item.h"



/////////////////////////
// Create main character

Character* makeCharacter(){
    Character* character;

	// Declaration of pointer/variables	
	std::string userInput;
	std::string classString;
	std::string subClass;

	// Greeting message

	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Character Builder" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
	cout << endl;
	cout << "To make a Fighter press \"f\"" << endl;

	// Loops until a user presses "f"
	while (true) {
		cin >> userInput;
		if (userInput == "f") {
			classString = "Fighter";
			break;
		}
		else {
			std::cout << "Please Enter a valid letter..." << std::endl;
		}
	}

	std::cout << "Choose a subclass between: Bully (b), Nimble (n), and Tank (t)" << std::endl;

	// Loops until a user selects a valid sub class
	while (true) {
		cin >> userInput;
		if (userInput == "b") {
			subClass = "Bully";
			character = new Bully();
			break;
		}
		else if (userInput == "n") {
			subClass = "Nimble";
			character = new Nimble();
			break;
		}
		else if (userInput == "t") {
			subClass = "Tank";
			character = new Tank();
			break;
		}
		else
			std::cout << "Please Enter A Valid Letter..." << std::endl;
	}

	cout << "Please enter a name for your character: " << std::endl;
	cin >> userInput;
	character->setCharacterName(userInput);
	cout << std::endl;

	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "STATS" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// Display level 1 stats
	character->displayStats();

	//load character default item inventory ( boots, weapon)
	character->loadDefaultInventory(character);

	
	Save* save = new Save();
	save->savePlayer(character);	
	std::cout << "\nCharacter has been saved" << std::endl;
    return character;
}

/////////////////////////////
// Display Computer diectory
void displayDirectory(std::string path){
    DIR *dir;
    struct dirent *ent;
	std::string newPath = DIRECTORY + path;

    if ((dir = opendir (newPath.c_str())) != NULL) {
      /* print all the files and directories within directory */
      std::cout << "\n=============================================\n" << std::endl;
      while ((ent = readdir (dir)) != NULL) {
        printf ("%s\n", ent->d_name);
      }
      closedir (dir);
      std::cout << "\n=============================================\n" << std::endl;
      std::cout << "Select From the List:" << std::endl;
    }else{
        std::cout << "Can't open directory!" << std::endl;
    }
}


void greeting(){
    // Greeting message
    std::cout << "\n=============================================\n" << std::endl;
    std::cout << "Greetings fellow adventurer!" << std::endl;
    std::cout << "\n=============================================\n" << std::endl;
    std::cout << "Enter \"Create\" to make a new campaign or \"Load\" to load one" << std::endl;
}

Campaign* createCampaign() {
	Campaign* campaign = new Campaign();
	std::string userInput;

	// Campaign Creation

	std::cout << "\n=============================================\n" << std::endl;
	std::cout << "Campaign";
	std::cout << "\n=============================================\n" << std::endl;

	std::cout << "Enter a name for your campaign" << std::endl;
	cin >> userInput;
	campaign->setName(userInput);

	// Map Creation
	std::cout << "\n=============================================\n" << std::endl;
	std::cout << "Map";
	std::cout << "\n=============================================\n" << std::endl;

	while (true) {
		Map* map = new Map();
		std::cout << "Enter a name for a map" << std::endl;
		cin >> userInput;
		map->setName(userInput);

		std::cout << "Enter map size: " << std::endl;
		int height, width;
		
		std::cout << "Width: ";
		cin >> width;
		std::cout << "\nHeight: ";
		cin >> height;
		cout << std::endl;
		
		MapObserver* observer = new MapObserver(map);
		map->resize(width, height);

		while (true) {
			// Set Map Panels
			std::cout << "Enter a panel on the map" << std::endl;

			// Panel objects
			int x;
			int y;
			char type;

			cout << "X: ";
			cin >> x;
			cout << "\nY: ";
			cin >> y;
			cout << "\nType: ";
			cin >> type;

			map->fillCell(x, y, type);

			badAnswer:
			cout << "\n\nWould you like to add additional panels? (y/n)" << std::endl;
			cin >> userInput;

			if (userInput == "n" || userInput == "N") {
				// Verify is there is a viable path
				if (map->findPath()) {
					campaign->addMap(map);
					break;
				}
				else {
					std::cout << "Map is incorrect. Either no possible path to an exit or spawn location and entrace on the same map\n" << std::endl;
				}
			}
			else if (userInput == "y" || userInput == "Y") {
			}
			else {
				std::cout << "Please enter (y/n)" << std::endl;
				goto badAnswer;
			}
		}

		std::cout << "Would you like to create a new map? (y/n)" << std::endl;
		
		//Retry user input as long as invalid
		retry:
		std::cin >> userInput;

		if (userInput == "n" || userInput == "N") {
			if ((campaign->getCampaignSize() == 1) && (campaign->returnMap(0)->verifyMapLinks() == false)) {
				cout << "Your map has an exit but no other maps exist. Please create a new map" << std::endl;
			}
			else if (!campaign->spawnLocation()) {
				cout << "None of your maps have a spawning area. Create map with a spawn" << std::endl;
			}
			else {
				break;
			}			
		}
		else if (userInput != "y" || userInput != "Y") {
			
		}
		else {
			std::cout << "Please enter \"y\" or \"n\"" << std::endl;
			goto retry;
		}
	}

	int campaignSize = campaign->getCampaignSize();

	// While loop makes sure that all maps are linked if necessary
	bool saveMaps = false;
	while (!saveMaps) {
		for (int i = 0; i < campaignSize; i++) {
			if (campaign->returnMap(i)->verifyMapLinks() == false){
				std::cout << "Map " << campaign->getMapName(i) << " is missing links." << std::endl;	
				Map* map1 = campaign->returnMap(i);
				Map* map2 = new Map();;

				// while loop make sures that user selects an existing map
				while (true) {
					std::cout << "Select from the list below to create link" << endl;
					campaign->displayMaps();
					std::cin >> userInput;
					
					bool mapFound = false;
					for (int j = 0; j < campaignSize; j++) {
						if (userInput == campaign->getMapName(j)) {
							mapFound = true;
							map2 = campaign->returnMap(j);
						}
					}
					//Make sure user doesn't input same map. Map must connect to another
					if (mapFound) {						
						if (map1->getName() == map2->getName()) {
							std::cout << "Please choose a different Map!" << std::endl;
							cout << std::endl;
						}
						else {
							break;
						}
					}
					else {
						std::cout << "Could not find map" << std::endl;
					}
				}
				int x1, x2, y1, y2;

				// While loops verifies that correct cells have been chosen to link maps
				bool mapLinked = false;
				while (!mapLinked) {					
					map1->printMap();
					map2->printMap();

					std::cout << "Enter entrance or exit from " << map1->getName() << std::endl;
					cout << "X: ";
					cin >> x1;
					cout << "\Y: ";
					cin >> y1;

					std::cout << "\nEnter entrance or exit from " << map2->getName() << std::endl;
					cout << "X: ";
					cin >> x2;
					cout << "\Y: ";
					cin >> y2;

					panel* p1 = map1->getPanel(x1, y1);
					panel* p2 = map2->getPanel(x2, y2);
					if (campaign->linkMaps(p1, p2)) {
						std::cout << "Maps have been successfully linked\n" << std::endl;
						mapLinked = true;
					}
					else {
						std::cout << "Couldn't link maps, make sure cells are correct\n" << std::endl;
					}
				}
			}
			else {
				saveMaps = true;;
			}
		}
	}

	//Sets the map that has a spawn point as the default
	campaign->setDefaultCurrentMap();
	Save* save = new Save();
	save->saveCampaign(campaign);	
	std::cout << "\nCampaign and maps have been saved!\n" << std::endl;
	return campaign;
}

Campaign* loadCampaign() {
	Campaign* campaign = new Campaign();
	std::cout << "Load a campaign from the following directory" << std::endl;
	displayDirectory("Campaign");
	std::string userInput;
	cin >> userInput;
	userInput = userInput.substr(0, userInput.find("."));
	Load* load = new Load();
	campaign = load->loadCampaign(userInput);
	return campaign;
}

//Add Items in Chest if it is on map
// A chest is designated by 'c'
void adaptedChest(int numberToAdd, int level, Map* m_map) {
	Item* item;

	for (int i = 0; i < m_map->getSizeWidth(); i++) {
		for (int j = 0; i < m_map->getSizeLength(); i++) {
			if (m_map->getCell(i, j) == 'c') {
				std::cout << "HELPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
			}
		}
	}
}

//function needed to adaptedMapToLevel(int level, Map* m_map)
void adaptedMonster(int level, Map* map) {
	Elemental* elemental;

	for (int i = 0; i < map->getSizeWidth(); i++) {
		for (int j = 0; j < map->getSizeLength(); j++) {
			if (map->getCell(i, j) == 'm') {
				if (level < 6) {
					elemental = new Elemental("small");
					elemental->setName("Air Elemental");
					map->getPanel(i, j)->setEnemy(elemental);
				}
				else if (level < 13) {
					elemental = new Elemental("medium");
					elemental->setName("Air Elemental");
					map->getPanel(i, j)->setEnemy(elemental);
				}
				else {
					elemental = new Elemental("large");
					elemental->setName("Air Elemental");
					map->getPanel(i, j)->setEnemy(elemental);
				}
			}
		}
	}
}

//Play
void play(Character* player, Campaign* campaign, panel* playerOnMap) {
	std::string userInput;
	panel* currentPanel = playerOnMap;


	// get map pointer
	for (int i = 0; i < campaign->getCampaignSize(); i++) {
		if (campaign->returnMap(i)->getName() == playerOnMap->getMapName()) {
			campaign->setCurrentMap(campaign->returnMap(i));
		}
	}

	while (true) {
	badAnswer:
		std::cout << "You are on Map: " << currentPanel->getMapName() << std::endl;
		campaign->getCurrentMap()->printMap();
		std::cout << "Enter a direction where you want to move (l=left,r=right,u=up,d=down). " << std::endl << "If you want to acces to character's identity press 'c', to your inventory press'i'" << std::endl;
		std::cin >> userInput;
		if (userInput == "r" || userInput == "R") {
			currentPanel = currentPanel->moveRight();
			currentPanel->setPlayer(player);
			if (currentPanel->Combat()) {
				if (player->getRemainingHp() <= 0) {
					std::cout << "\nYOU HAVE DIED\n" << std::endl;
					Save* save = new Save();
					save->savePlayer(player);
					break;
				}
			}
		}
		else if (userInput == "l" || userInput == "L") {
			currentPanel = currentPanel->moveLeft();
			currentPanel->setPlayer(player);
			if (currentPanel->Combat()) {
				if (player->getRemainingHp() <= 0) {
					std::cout << "\nYOU HAVE DIED\n" << std::endl;
					Save* save = new Save();
					save->savePlayer(player);
					break;
				}
			}
		}
		else if (userInput == "u" || userInput == "U") {
			currentPanel = currentPanel->moveDown();
			currentPanel->setPlayer(player);
			if (currentPanel->Combat()) {
				if (player->getRemainingHp() <= 0) {
					std::cout << "\nYOU HAVE DIED\n" << std::endl;
					Save* save = new Save();
					save->savePlayer(player);
					break;
				}
			}
		}
		else if (userInput == "d" || userInput == "D") {
			currentPanel = currentPanel->moveUp();
			currentPanel->setPlayer(player);
			if (currentPanel->Combat()) {
				if (player->getRemainingHp() <= 0) {
					std::cout << "\nYOU HAVE DIED\n" << std::endl;
					Save* save = new Save();
					save->savePlayer(player);
					break;
				}
			}
		}
		else if (userInput == "c" || userInput == "C") {
		player->displayStats();
		}
		else if (userInput == "Save") {
			Save* save = new Save();
			save->savePlayer(player);
			//save inventory as well

			//save inventory
			ItemsSaving *c = new ItemsSaving();
			c->saveInventoryPlayer(player);

			std::cout << "\n PLAYER HAS BEEN SAVED \n" << std::endl;
		} 
		else if (userInput == "i" || userInput == "I") {
			bool loop = true;
			string inputK;
			int inputk2;
			player->displayInventory();
			while (loop) {
				std::cout << "If you would like to use an item , please enter -use- or to go back to the game enter -x-" << std::endl;
				std::cin >> inputK;

				if (inputK == "use"){
					cout << "Enter the ITEM # you want to use." << std::endl;
					cin >> inputk2;
					
					player->useItem(player, inputk2);
					loop = false;
				}
				else if (inputK == "x") {
					loop = false;
				}
			}

		}  
		else {
			std::cout << "Please enter r, l, u, d, c, b, Save" << std::endl;
			goto badAnswer;
		}

			// going from exit to entrance
			if (currentPanel->getPanelType() == 'x') {
				Map* map = new Map();
				currentPanel = currentPanel->getEntrance();
				for (int i = 0; i < campaign->getCampaignSize(); i++) {
					if (campaign->returnMap(i)->getName() == currentPanel->getMapName()) {
						campaign->setCurrentMap(campaign->returnMap(i));
						map = campaign->returnMap(i);
					}
				}
				if (map->getVisited() == false) {
					player->ForceLevelUp();
					adaptedMonster(player->getLevel(), map);
					map->setVisited(true);
					
					bool foundX = false;
					//Check if last level
					for (int i = 0; i < map->getSizeWidth(); i++) {
						for (int j = 0; j < map->getSizeLength(); j++) {
							if (map->getCell(i, j) == 'x') {
								foundX = true;
							}
						}
					}
					if (foundX == false) {
						std::cout << "\nYOU BEAT THE GAME\n" << std::endl;
						map->printMap();
						break;
					}
				}

			}
			// if character enters an entrance
			else if (currentPanel->getPanelType() == 'e') {
				currentPanel = currentPanel->getExit();
				for (int i = 0; i < campaign->getCampaignSize(); i++) {
					if (campaign->returnMap(i)->getName() == currentPanel->getMapName()) {
						campaign->setCurrentMap(campaign->returnMap(i));
					}
				}
			}
		}
	}
		//FIN = (!((player->getHitPoints()) == 0)); /////////////////////////////////////////////////////////////////////////////////////////////REVOIR CONDITION

// Create or load a campaign
Campaign* loadOrCreate() {
	Campaign* campaign = new Campaign();
	std::string userInput;
	while (true) {
		cin >> userInput;
		if (userInput == "Create") {
			campaign = createCampaign();
			break;
		}
		else if (userInput == "Load") {
			campaign = loadCampaign();
			break;
		}
		else {
			std::cout << "Please enter valid info" << endl;
		}

	}
	return campaign;
}


// Loading a character
Character* loadCharacter() {
	Character* character = new Character(); 
	std::cout << "Load a Character from the following directory" << std::endl;
	displayDirectory("Player");
	std::string userInput;
	cin >> userInput;
	userInput = userInput.substr(0, userInput.find("."));
	Load* load = new Load();
	character = load->loadPlayer(userInput);
	//////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	std::cout << "\n CHARACTER LOADED\n" << std::endl;
	//character->displayStats();
	 

	//items
	ItemsSaving *c = new ItemsSaving(); 
	std::cout << "Load an item inventory from the following directory :" << std::endl;
	displayDirectory("Items");
	std::string userInput1;
	userInput1 = userInput1.substr(0, userInput1.find("."));
	cin >> userInput1;
	c->loadInventoryItems(character, userInput1);

	std::cout << "\n ITEMS LOADED\n" << std::endl;

	return character;
}

// Create or load a campaign
Character* loadOrCreateChar() {
	Character* character = new Character();
	std::string userInput;
	std::cout << "Enter \"Create\" to make a new Character or \"Load\" to load one" << std::endl;
	while (true) {
		cin >> userInput;
		if (userInput == "Create") {
			character = makeCharacter();
			break;
		}
		else if (userInput == "Load") {
			character = loadCharacter();
			break;
		}
		else {
			std::cout << "Please enter valid info" << endl;
		}

	}
	return character;
}