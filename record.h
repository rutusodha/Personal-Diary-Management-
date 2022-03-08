#ifndef RECORD_H
#define RECORD_H


class record{
    char *username;
    char *email;
	char time[10];
	char name[30];
	char place[25];
	char duration[10];
	char note[500];
    char passwords[25];
	public:
	    record();
	    ~record();
		void add_record();
		void view_record();
		void modify_record();
		void delete_record();
		void edit_password();
		int password();
		void signup(char*,char*);
		void signin(char*);
};

#endif // RECORD_H
