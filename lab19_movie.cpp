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
                return;
            }
            Node *current = head;   // Start at the head of the list
            // Traverse the link list and print each review
            while (current){
                cout << "\tRating : " << fixed << setprecision(1) << current->val << " | Comment :" << current->comment << endl; 
                current = current->next;    // Move to the next node
            }
            cout << endl;

        }

    };
    

// Function prototype
// Function to open a file and return a status code (1 for success, 0 for failure)
int openfile (fstream &f, string filename );

int main(){
    
    fstream f;                              // Filestream objects
    string filename = "reviewsfile.txt";    // Input file for review comments
    string line = "";                       // Temporary variable to store comments s
    vector <Movie> movie_vect;              // Vector to store Movie objects
    vector <string> comments;               // Vector to store comments from file

    if (openfile(f,filename) !=  1){
        exit (-1);
    }

    // Array of movie titles for testing
    string movietitles[4] = {"Lord of the Rings", "Raiders of the Lost Ark", "Mission Impossible", "John Wick"};
    // Read all review comments from the file and store them in the comments vector
    while (getline(f,line)){        
        comments.push_back(line);
    }
    // Verify file has contents.
    if (comments.empty()){
        cout << "No comments available in the file. Aborting program." << endl;
        return (-1);
    }

    // Read each line (review comment) from the file and store it in the comments vector
    for (int i = 0; i < 4; i++){
        Movie movietemp;
        movietemp.settitle(movietitles[i]);
        
        // Set up random generator to randomly select a comment from the comments vector
        random_device seed;
        mt19937 gen(seed());
        uniform_int_distribution<> comm_dist(0, comments.size() -1);

        // Loop to add 4 reviews for each movie
        for (int j = 0; j < 4; j++){
            double temprating = movietemp.getrating();      // Generate random rating
            string random_comments = comments[comm_dist(gen)]; // Select a random comment
            movietemp.add_node_front(temprating,random_comments); // Add review node to the movie's linked list
        }
        movie_vect.push_back(movietemp);  // Add the movie object to the movie vector
    }

    // Loop to print all reviews for each movie in the vector
    for (Movie m : movie_vect){
        m.print_reviews();
    }
    // Close the file stream
    f.close();
    return 0;
}

// Function to open a file and check for errors
// arguments: filestream and filename
// returns: integer (1 for success, 0 for failure)
int openfile(fstream &f, string filename){
    f.open(filename, ios::in);
    if(!f){
        cout << "\nError opening file. Aborting program\n";
        return 0;
    } 
    else 
        return 1;
}

