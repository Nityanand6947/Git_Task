#include <iostream>
#include <map>
using namespace std;

struct ThemeSkin
{
    string backgroundColor;
    string fontColor;
    int fontSize;
    string iconStyle;

    // Default constructor
    ThemeSkin() : backgroundColor("default"), fontColor("default"), fontSize(12), iconStyle("default") {}

    // Parametrized constructor
    ThemeSkin(string a, string b, int c, string d)
    {
        backgroundColor = a;
        fontColor = b;
        fontSize = c;
        iconStyle = d;
    }
};

class Theme
{
    map<int, ThemeSkin> themes;
    int currentKey = 1; // To keep track of the theme key

public:
    void addTheme(const ThemeSkin &theme)
    {
        themes.insert({currentKey++, theme});
    }

    void applyTheme(int key,string theme)
    {
        if (themes.find(key) != themes.end())
        {
            ThemeSkin appliedTheme = themes[key];
            cout << "Applying theme: " <<theme<< endl;
            cout << "Background Color: " << appliedTheme.backgroundColor << endl;
            cout << "Font Color: " << appliedTheme.fontColor << endl;
            cout << "Font Size: " << appliedTheme.fontSize << endl;
            cout << "Icon Style: " << appliedTheme.iconStyle << endl;
        }
        else
        {
            cout << "Theme not found! " << endl;
        }
    }
};

class Reload
{
    Theme themeManager;

public:
    Reload()
    {
        themeManager.addTheme(ThemeSkin("GreyishBlack", "NavyBlueish", 12, "OldSchoolIcon"));
        themeManager.addTheme(ThemeSkin("WarmRed", "AthleteYellow", 20, "EnergyIcon"));
        themeManager.addTheme(ThemeSkin("OrangeDimple", "ParishGreen", 16, "SimpleModelIcon"));
    }

    Theme getThemeManager()
    {
        return themeManager;
    }
};

int main()
{
    // Initialize Reload object and themes once
    Reload rd;
    Theme themeManager = rd.getThemeManager();

    int data;
    bool flag = true;

    while (flag)
    {
        cout << "\n1. Classic Theme \n2. Sports Theme \n3. Eco Theme\n0. Exit" << endl;
        cout << "Choose a theme (1-3) & 0 to exit: ";
        cin >> data;

        switch (data)
        {
        case 1:
            themeManager.applyTheme(1,"Classic"); // Classic Theme
            break;
        case 2:
            themeManager.applyTheme(2,"Sports"); // Sports Theme
            break;
        case 3:
            themeManager.applyTheme(3,"Eco"); // Eco Theme
            break;
        case 0:
            cout << "\nExiting the program." << endl;
            flag = false;
            break;
        default:
            cout << "Invalid choice! Please select a valid option." << endl;
            break;
        }
    }

    return 0;
}
