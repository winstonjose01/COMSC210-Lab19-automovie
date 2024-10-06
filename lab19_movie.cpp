// COMSC210 | Lab19 | Winston Jose
// IDE Used: Visual Studio code
// Github Link:

# include <iostream>
# include <fstream>
using namespace std;


class Movie {
    private:
        string movietitle;
        struct Node {
            double val;
            string comment;
            Node *next;
        };
        Node * head;
    public:

        Movie(){
            movietitle = "";
            head = nullptr;

    }

    




};


int main(){
    
    fstream f;
    string filename = "reviewsfile.txt";
    string line = "";
    vector <Movie> movie_vect;


    return 0;
}


int openfile(fstream &f, string filenames){
    if(!f){
        cout << "\nError opening file. Aborting program\n";
        return 0;
    } 
    else 
        return 1;
}

