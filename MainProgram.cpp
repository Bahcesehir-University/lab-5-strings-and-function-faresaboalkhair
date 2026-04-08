// ---- Constructors ----

MyString::MyString() {
    data = "";
}

MyString::MyString(const string& str) {
    data = str;
}

MyString::MyString(const char* str) {
    data = str;
}

// ---- Getter ----

string MyString::getData() const {
    return data;
}

// ---- Basic String Operations ----

int MyString::length() const {
    return data.length();
}

char MyString::charAt(int index) const {
    if (index < 0 || index >= length())
        throw out_of_range("Index out of range");
    return data[index];
}

MyString MyString::substring(int start, int len) const {
    if (start < 0 || start >= length())
        throw out_of_range("Start index out of range");
    return MyString(data.substr(start, len));
}

// ---- String Manipulation ----

MyString MyString::toUpperCase() const {
    string temp = data;
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    return MyString(temp);
}

MyString MyString::toLowerCase() const {
    string temp = data;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    return MyString(temp);
}

MyString MyString::trim() const {
    size_t start = data.find_first_not_of(" \t\n\r");
    size_t end = data.find_last_not_of(" \t\n\r");

    if (start == string::npos)
        return MyString("");

    return MyString(data.substr(start, end - start + 1));
}

MyString MyString::reverse() const {
    string temp = data;
    std::reverse(temp.begin(), temp.end());
    return MyString(temp);
}

// ---- Search Operations ----

int MyString::find(const MyString& target) const {
    size_t pos = data.find(target.data);
    return (pos == string::npos) ? -1 : (int)pos;
}

int MyString::count(char ch) const {
    return std::count(data.begin(), data.end(), ch);
}

// ---- Function Overloading: append ----

MyString MyString::append(const MyString& other) const {
    return MyString(data + other.data);
}

MyString MyString::append(const char* cstr) const {
    return MyString(data + string(cstr));
}

MyString MyString::append(char ch) const {
    return MyString(data + ch);
}

MyString MyString::append(int number) const {
    return MyString(data + to_string(number));
}

// ---- Function Overloading: replace ----

MyString MyString::replace(char oldCh, char newCh) const {
    string temp = data;
    for (char& c : temp) {
        if (c == oldCh) c = newCh;
    }
    return MyString(temp);
}

MyString MyString::replace(const string& oldStr, const string& newStr) const {
    string temp = data;
    size_t pos = 0;

    while ((pos = temp.find(oldStr, pos)) != string::npos) {
        temp.replace(pos, oldStr.length(), newStr);
        pos += newStr.length(); // move forward to avoid infinite loop
    }

    return MyString(temp);
}

// ---- Operator Overloading ----

MyString MyString::operator+(const MyString& other) const {
    return MyString(data + other.data);
}

bool MyString::operator==(const MyString& other) const {
    return data == other.data;
}

bool MyString::operator!=(const MyString& other) const {
    return data != other.data;
}

bool MyString::operator<(const MyString& other) const {
    return data < other.data;
}

bool MyString::operator>(const MyString& other) const {
    return data > other.data;
}

char MyString::operator[](int index) const {
    if (index < 0 || index >= length())
        throw out_of_range("Index out of range");
    return data[index];
}

MyString MyString::operator*(int times) const {
    if (times <= 0) return MyString("");

    string result;
    for (int i = 0; i < times; i++) {
        result += data;
    }
    return MyString(result);
}

// ---- Stream Overloading ----

ostream& operator<<(ostream& os, const MyString& s) {
    os << s.data;
    return os;
}

istream& operator>>(istream& is, MyString& s) {
    is >> s.data;
    return is;
}
