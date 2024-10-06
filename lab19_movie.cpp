// COMSC210 | Lab19 | Winston Jose
// IDE Used: Visual Studio code
// Github Link:

# include <iostream>
# include <fstream>
# include <vector>
using namespace std;


class Movie {
    private:
        string movietitle;
        struct Node {
            double val;
            string comment;
            Node *next;
            // Node constructor
            Node (double v, string c){
                val = v; comment = c; next = nullptr;
            }
        };
        Node * head;
    public:

        Movie(){
            movietitle = "";
            head = nullptr;
        }
        void add_node_front(double rating, string com){
            Node *newNode = new Node (rating, com);
            newNode->next = head;
            head = newNode;
        }

    };

// Function prototype
int openfile (fstream &, string );

int main(){
    
    fstream f;
    string filename = "reviewsfile.txt";
    string line = "";
    vector <Movie> movie_vect;
    vector <string> comments;  // Vector to hold comments 

    if (openfile(f,filename) !=  1){
        exit (-1);
    }

    string movietitles[4] = {"Lord of the Rings", "Raiders of the Lost Ark", "Mission Impossible", "John Wick"};

    while (getline(f,line)){        // Stoe all comments tothe vectors
        comments.push_back(line);
    }
    
    for i

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

