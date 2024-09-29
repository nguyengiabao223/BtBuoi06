class DVD : public Brrowsble {
    private :
    string title;
    string director;
    int duration;
    bool available;
    public : 
    DVD(string t, string d, int dur ) : title(move(t)), director(move(d)), duration(dur), available(true) {}
 
};