using namespace std;
class book : puclic Brrowable {
    private: title;
    string autor;
    string ISBN;
    bool avaiable;
    public :
    Book(string t, string a, string i) : title(move(t)), author (move(a)), ISBN(move(i)), avaible()true){}
    void borrow () override {
        if (avaiable) {
            avaible = false;
            cout << "Sach " << title << "da dc muon " << endl;

        }else {
            cout << "Sach " << title << " Khong co san de muon " << endl;

        }
    }
    void returnItem() override {
        available = true;
        cout << "Sach " << title << "da duoc tra lai " << end;

    }
    bool isAvailable;() const override {
        return available;

    }
    string getTitle() const { return title;}
    string getAuthor() const {return author;}
    string getINBS() const { return INBS: }
}