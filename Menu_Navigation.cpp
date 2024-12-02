#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MenuItem {
public:
    virtual void display() const = 0;
    virtual void showOptions() const = 0;
    virtual MenuItem* navigate(int choice) = 0;
};

class DisplaySetting : public MenuItem {
public:
    void display() const override {
        cout << "-> Display\n";
    }

    void showOptions() const override {
        // Display options here if needed
    }

    MenuItem* navigate(int choice) override {
        // Handle deeper navigation in DisplaySetting if needed (for now just return this)
        return nullptr;  // No deeper menu, return null
    }
};

class AudioSetting : public MenuItem {
public:
    void display() const override {
        cout << "-> Audio\n";
    }

    void showOptions() const override {
        // Audio options here if needed
    }

    MenuItem* navigate(int choice) override {
        // Handle deeper navigation in AudioSetting (for now just return this)
        return nullptr;  // No deeper menu, return null
    }
};

class SettingMenu : public MenuItem {
public:
    vector<MenuItem*> options;

    SettingMenu() {
        options.push_back(new DisplaySetting());
        options.push_back(new AudioSetting());
    }

    void display() const override {
        cout << "-> Settings\n";
    }

    void showOptions() const override {
        cout << "1. Display\n";
        cout << "2. Audio\n";
    }

    MenuItem* navigate(int choice) override {
        if (choice == 1) {
            return options[0]; // Navigate to Display
        } else if (choice == 2) {
            return options[1]; // Navigate to Audio
        }
        return nullptr; // Invalid choice
    }
};

class Radio : public MenuItem {
public:
    void display() const override {
        cout << "-> Radio\n";
    }

    void showOptions() const override {
        // No further options for Radio
    }

    MenuItem* navigate(int choice) override {
        return nullptr;  // No deeper menu
    }
};

class BluetoothAudio : public MenuItem {
public:
    void display() const override {
        cout << "-> Bluetooth Audio\n";
    }

    void showOptions() const override {
        // No further options for Bluetooth Audio
    }

    MenuItem* navigate(int choice) override {
        return nullptr;  // No deeper menu
    }
};

class MediaMenu : public MenuItem {
public:
    vector<MenuItem*> options;

    MediaMenu() {
        options.push_back(new Radio());
        options.push_back(new BluetoothAudio());
    }

    void display() const override {
        cout << "-> Media\n";
    }

    void showOptions() const override {
        cout << "1. Radio\n";
        cout << "2. Bluetooth Audio\n";
    }

    MenuItem* navigate(int choice) override {
        if (choice == 1) {
            return options[0]; // Navigate to Radio
        } else if (choice == 2) {
            return options[1]; // Navigate to Bluetooth Audio
        }
        return nullptr; // Invalid choice
    }
};

class MainMenu : public MenuItem {
public:
    vector<MenuItem*> options;

    MainMenu() {
        options.push_back(new SettingMenu());
        options.push_back(new MediaMenu());
    }

    void display() const override {
        cout << "-> Main Menu\n";
    }

    void showOptions() const override {
        cout << "1. Settings\n";
        cout << "2. Media\n";
    }

    MenuItem* navigate(int choice) override {
        if (choice == 1) {
            return options[0]; // Navigate to Settings
        } else if (choice == 2) {
            return options[1]; // Navigate to Media
        }
        return nullptr; // Invalid choice
    }
};

// Function to manage navigation
void navigate(MenuItem* currentMenu) {
    int choice = -1;
    MenuItem* nextMenu = nullptr;

    while (true) {
        currentMenu->display();
        currentMenu->showOptions();
        
        cout << "Enter your choice (0 to go back): ";
        cin >> choice;

        if (choice == 0) {
            break;  // Go back to the previous menu
        }

        nextMenu = currentMenu->navigate(choice);
        if (nextMenu) {
            // Go deeper into the selected submenu
            navigate(nextMenu);
            currentMenu = nextMenu; // Update current menu to the next menu
        } else {
            cout << "No child node available .\n";
        }
    }
}

int main() {
    MainMenu mainMenu;
    navigate(&mainMenu); // Start navigation from the main menu

    return 0;
}

/*

#include <iostream>
using namespace std;
class Display_Setting
{
public:
    void display()
    {
        cout << "-> Display" << endl;
    }
};
class Audio_Setting
{
public:
    void display()
    {
        cout << "-> Audio" << endl;
    }
};

class Setting
{
public:
    Display_Setting display1;
    Audio_Setting audio;

    void display()
    {
        cout << "-> Setting" << endl;
    }

    void showLeftDisplay()
    {
        display1.display();
    }

    void showRightDisplay()
    {
        audio.display();
    }
};
class Radio
{
public:
    void display()
    {
        cout << "-> Radio" << endl;
    }
};
class BlueTooth_Audio
{
public:
    void display()
    {
        cout << "-> BlueTooth Audio" << endl;
    }
};

class Media
{
public:
    Radio radio;
    BlueTooth_Audio bluetooth;

    void display()
    {
        cout << "-> Media" << endl;
    }
    void showLeftDisplay()
    {
        radio.display();
    }

    void showRightDisplay()
    {
        bluetooth.display();
    }
};

class Main_Menu
{
public:
    Setting inner1;
    Media inner2;

    void display(){
        cout<<"-> Main Menu "<<endl;
    }

    void showLeftDisplay()
    {
        inner1.display();
    }

    void showRightDisplay()
    {
        inner2.display();
    }
};

struct Node
{
    Main_Menu data;
    Node *leftptr;
    Node *rightptr;

    Node(Main_Menu val)
    {
        data = val;
        leftptr = rightptr = NULL;
    }
};

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    // root->data.display();

    inorderTraversal(root->leftptr);

    if (root->leftptr != NULL)
    {
        //root->data.display();
        root->data.showLeftDisplay();
    }

    if (root->rightptr != NULL)
    {
        //root->data.display();
        root->data.showRightDisplay();
    }

    inorderTraversal(root->rightptr);
}

int main()
{

    Node *root = new Node(Main_Menu());
    root->leftptr = new Node(Main_Menu());
    root->rightptr = new Node(Main_Menu());

    root->leftptr->leftptr = new Node(Main_Menu());
    root->leftptr->rightptr = new Node(Main_Menu());

    root->rightptr->leftptr = new Node(Main_Menu());
    root->rightptr->rightptr = new Node(Main_Menu());

    cout << "In-order Traversal Output:" << endl;
    inorderTraversal(root);

    return 0;
}
Take one current pointer and point it to Main Menu and then 
ask user to go 1 for up , 2 for down and 3 for enter and 0 for back
if up then current pointer should show settign and if down then Media
Adain if user enter take him inside and then in settign keep up as display and down as audio
and in media keep up radio and down bluetooh and is should display as per user command and everytime
current pointer should get update and back for previous node and update the current node
*/