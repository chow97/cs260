class student
{
private:
    char* name;
    int terms;

public:
    
    student();
    student(const char* n,int t);
    student(const student& other);
    ~student();
    const sutdent& operator=(const student& other);

    void print();

    const char* getName();
    int getTerms();

    void setName(const char* newname);
    void setTerms(int newterms);

    student operator+(student& other);

    friend std::ostream& operator<<(std::ostream& out,student& s);
};


