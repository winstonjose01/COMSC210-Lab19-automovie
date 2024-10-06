// COMSC210 | Lab19 | Winston Jose
// IDE Used: Visual Studio code
// Github Link:

# include <iostream>
# include <fstream>
# include <vector>
# include <random>
# include <iomanip>
using namespace std;
// Movie class to store movie reviews
class Movie {              
    private:
        // Constants for rating change
        const double RATING_MIN = 1.0; 
        const double RATING_MAX = 5.0;
        string movietitle; // Movie title
        // Struct to represent a node in the linked list (rating, comment)
        struct Node {
            double val;         // Review rating
            string comment;     // Review comment
            Node *next;         // Pointer to next node on the list
            // Node constructor to initialize the list
            Node (double v, string c){
                val = v; comment = c; next = nullptr; 
            }
        };
        Node * head;    // Pointer to the head of the linked list

    public: 
        // Default constructor for Movie object (initializes empty movie title and linked list)
        Movie(){
            movietitle = "";
            head = nullptr;
        }

        // Function to add a new review node at the front of the linked list
        void add_node_front(double rating, string com){
            Node *newNode = new Node (rating, com);     // Creates a new node
            newNode->next = head;                       // New node points to the current head
            head = newNode;                             // Update head to the new node
        }

        // Function to set the movie title
        void settitle(string title){
            movietitle = title;
        }

        // Function to generate a random rating between RATING_MIN and RATING_MAX
        double getrating(){
            random_device seed;
            mt19937 gen(seed());
            uniform_real_distribution<> rating(RATING_MIN, RATING_MAX);
            return (rating(gen));   // Return random rating
        }

        // Function to print all reviews for the movie (title and linked list contents)
        void print_reviews(){
            cout << "Reviews for " << movietitle << endl;
            // Check if the linked list is empty
            if (!head){
                cout << "Review list is empty.";
                exit (0);
            }
            Node *current = head;   // Start 
            while (current){
                cout << "\tRating : " << fixed << setprecision(1) << current->val << " | Comment :" << current->comment << endl; 
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

