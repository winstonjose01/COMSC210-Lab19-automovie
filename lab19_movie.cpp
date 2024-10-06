// COMSC210 | Lab19 | Winston Jose
// IDE Used: Visual Studio code
// Github Link:

# include <iostream>
# include <fstream>
# include <vector>
# include <random>
# include <iomanip>
using namespace std;



class Movie {
    private:
        const double RATING_MIN = 1.0;
        const double RATING_MAX = 5.0;
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
        void settitle(string title){
            movietitle = title;
        }

        double getrating(){
            random_device seed;
            mt19937 gen(seed());
            uniform_real_distribution<> rating(RATING_MIN, RATING_MAX);
            return (rating(gen));

        }

        void print_reviews(){
            cout << "Reviews for " << movietitle << endl;
            if (!head){
                cout << "Review list is empty.";
                exit (0);
            }
            Node *current = head;
            while (current){
                cout << "\tRating : " << fixed << setprecision(2) << current->val << " | Comment :" << current->comment << endl; 
                current = current->next;
            }
            cout << endl;

        }

    };
    

// Function prototype
int openfile (fstream &f, string filename );

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

    for (int i = 0; i < 4; i++){
        Movie movietemp;
        movietemp.settitle(movietitles[i]);

        random_device seed;
        mt19937 gen(seed());
        uniform_int_distribution<> comm_dist(0, comments.size() -1);

        for (int j = 0; j < 4; j++){
            double temprating = movietemp.getrating();
            string random_comments = comments[comm_dist(gen)];
            movietemp.add_node_front(temprating,random_comments);
        }
        movie_vect.push_back(movietemp);
    }
    for (Movie m : movie_vect){
        m.print_reviews();
    }
    
    f.close();
    return 0;
}


int openfile(fstream &f, string filename){
    f.open(filename, ios::in);
    if(!f){
        cout << "\nError opening file. Aborting program\n";
        return 0;
    } 
    else 
        return 1;
}

