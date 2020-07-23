#include <string>
#include <iostream>
using namespace std;

class OfficeFurniture {

public:
    int page; // from the number of page of the magazine depends what kind of office furniture you use choose
    string model; // what furniture you have chosen

    OfficeFurniture(int page = 2): page(page) {
        switch (page) {
            case 0 : model = "chairs";
                break;
            case 1 : model = "reception";
                break;
            case 2 : model = "table";
                break;
            case 3 : model = "reception";
                break;
            default: model = "table";
        }
    }
    // copy constructor
    OfficeFurniture(const OfficeFurniture& oF):
    model(oF.model),
              page(oF.page)
    {
    }
// destructor
    virtual ~OfficeFurniture()
    {
    }

};

class Table : OfficeFurniture {
    class Boxes {
    public:
        int numberOfBoxes;
        bool isOccupied;
        string things;

        Boxes(string things ="rubber, pen", int numberOfBoxes = 4, bool isOccupied = true) :
        things(things),
        numberOfBoxes(numberOfBoxes),
        isOccupied(isOccupied)
        {

        }

        Boxes(const Boxes& b) : things(b.things), numberOfBoxes(b.numberOfBoxes), isOccupied(b.isOccupied) {}
        friend ostream& operator<<(ostream& output, const Table& T);


    };

    class WorkTop {
        string material;
        string colour;
        double area; // m
    public:
        WorkTop(string material = "wood", string colour = "black", double area = 1.55) :
       material(material),
       colour(colour),
       area(area)
       {

       }

        WorkTop(const WorkTop& w) :
        material(w.material),
        colour(w.colour),
        area(w.area)
        {

        }
        friend ostream& operator<<(ostream& output, const Table& T);
    };

public:
    bool addOn;
    string colourOfScreen;
    string materialOfScreen;
    WorkTop workTop;
    Boxes boxes;
    OfficeFurniture officeFurniture;

    void keepThings(string things) {
        if (boxes.isOccupied) {
            cout << "Making table free from things" << endl;
            boxes.isOccupied = false;
        }
        if (!boxes.isOccupied) {
            boxes.things = things;
            cout << "Now  you keep "  + boxes.things + " in the table" << endl;
        }
    }

    void getThings() {
        cout << "In the table you keep " << boxes.things << endl;
    }
    Table(int page = 2,
          int numberOfBoxes = 4,
          bool isOccupied = true,
          string things = "pen, rubber",
          string material = "wood",
          string colour = "black",
          double area = 3.25,
          bool addOn = true,
          string colourOfScreen = "white",
          string materialOfScreen = "metal") :
            officeFurniture(page),
            boxes(Boxes(things, numberOfBoxes, isOccupied)),
            workTop(WorkTop(material, colour, area)),
            addOn(addOn),
            colourOfScreen(colourOfScreen),
            materialOfScreen(materialOfScreen)
            {

            }
};

ostream& operator<<(ostream& output, const Table& T) {
    output << "page of the magazine: " << T.officeFurniture.page << "that contains " << T.officeFurniture.model << endl;
    output << "Quantity of boxes: " << T.boxes.numberOfBoxes << endl;
    output << (T.boxes.isOccupied ? "The tiger is hungry" : "The tiger is not hungry") << endl;
    output << "In the boxes you have: " << T.boxes.things << endl;
    output << "The area of the worktop is: " << T.workTop.area << endl;
    output << "The colour of worktop is:  " << T.workTop.colour<< endl;
    output << "The material of worktop is: " << T.workTop.material << endl;
    output << "Is the table contain add on: " << T.addOn << endl;
    output << "The colour of the screen is: " << T.colourOfScreen << endl;
    return output;
}

int main() {
    Table table(2,
            5,
            true,
            "scissors_magazine",
            "metal", "pink",
            2.55,
            true,
            "magento",
            "plastic");

    Table table1 = table;
    cout<< table1<< endl;
    table1.keepThings("Notebook_meat");
    table1.getThings();

}
