

                        ///  name: hesham abdelmohsen abdallah hassan

                        ///    id: 20180330


#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <ctime>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;
                                ///  transopotatation varaibles

int mychoice,keep,n,g,i,right_answer=0,wrong_answer=0,number_of_quizes=0,total_right=0,total_wrong=0,b,complete_rand,total_quiz_grade,counter=0;
char character,view_all_users_answer;
vector<int>right_ans,wrong_ans,mcq_grades,tf_grades,complete_grades,right_choice,quizes_grades;
vector<char>vcharacter;
vector<string>tf_answer,complete_answer;
static int id =0 ;          /// for stat ids for question

string fname,lname,tfanswer,completeanswer;
string uname,pword;


class users
{

    public:
        void logout()
         {
          cout<<"you logged out\n";
         }

         void exist()
         {
             terminate();
         }
};
///*******************************************************************///
class mcq
{

public:

    string question;
    string choice1;
    string choice2;
    string choice3;
    string choice4;
    string right;
    int quistion_id = id++;

public:

    void setinfo()
    {               /// take choices & store the right one

        cout<<"enter 4 choices:\n";
        cout<<"first one is the right:\n";
        cin>>choice1>>choice2>>choice3>>choice4;

        right = choice1;
    }

///--------------------------------///
    int operator == (mcq x)
        {
            /// chech repeated questions

            if(question==x.question)
                return 1;
            else
                return 0;
        }

///--------------------------------///

    void view_all_question(vector<mcq> &vmcq)
    {
           ///view all mcq question

        cout<<"MC Questions list (Total: "<<vmcq.size()<<" Questions) \n";
        for(int i=0;i<vmcq.size();i++)
        {
            cout<<"["<<i+1<<"]"<<"(id = "<<vmcq[i].quistion_id<<")"<<vmcq[i].question<<"\n";
            cout<<"   "<<"*[a]"<<vmcq[i].choice1<<"   "<<"[b]"<<vmcq[i].choice2<<"   "<<"[c]"<<vmcq[i].choice3<<"   "<<"[d]"<<vmcq[i].choice4<<"\n";
        }
    }


///************************************///

    void random(vector<mcq> &vmcq)
    {
        ///make randomization for mcq questios & choices

        mcq arr[50];
        string choices[4];

        for(int i=0;i<vmcq.size();i++){

            arr[i]=vmcq[i];

        }

        srand(unsigned(time(0)));

        random_shuffle(arr, arr + vmcq.size());

        for(int i=0;i<vmcq.size();i++){
            vmcq[i]=arr[i];

        }
        ///------------------------------------///
        /// choices
        for(int i=0;i<vmcq.size();i++){

            choices[0]=vmcq[i].choice1;
            choices[1]=vmcq[i].choice2;
            choices[2]=vmcq[i].choice3;
            choices[3]=vmcq[i].choice4;


            srand(unsigned(time(0)));

            random_shuffle(choices, choices + 4);

            vmcq[i].choice1=choices[0];
            vmcq[i].choice2=choices[1];
            vmcq[i].choice3=choices[2];
            vmcq[i].choice4=choices[3];

        }



    }

    ///***********************************************///

    start_new_quiz(vector<mcq> &vmcq,vector<mcq> &template_mcq)
    {
       /// start new quiz (3 mcq questions per quiz )

        total_quiz_grade=0;
        number_of_quizes+=1;

        int quiz_choices_grade = 0;

        random(vmcq);

        for(int i=0 ; i<3;i++){
                template_mcq.push_back(vmcq[i]);
        }


       cout<<"******************************************\n";



///----------------------------///

        for (int i=0; i<3 ; i++){

            cout <<"["<<i+1<<"]"<<vmcq[i].question << "\n";
            cout<<"   "<<"[a]"<<vmcq[i].choice1<<"   "<<"[b]"<<vmcq[i].choice2<<"   "<<"[c]"<<vmcq[i].choice3<<"   "<<"[d]"<<vmcq[i].choice4<<"\n";

            cin>>character;
            vcharacter.push_back(character);

            switch(character)
            {
            case 'a':

                if (vmcq[i].choice1==vmcq[i].right){
                    right_answer+=1;
                    quiz_choices_grade += 1 ;
                    right_choice.push_back(1);}
                else{
                    wrong_answer+=1;
                    right_choice.push_back(0);
                }
                break;
            case 'b':
                if (vmcq[i].choice2==vmcq[i].right){
                    right_answer+=1;
                    quiz_choices_grade += 1 ;
                    right_choice.push_back(1);}
                else{
                    wrong_answer+=1;
                    right_choice.push_back(0);}
                break;

            case 'c':
                if (vmcq[i].choice3==vmcq[i].right){
                    right_answer+=1;
                    quiz_choices_grade += 1 ;
                    right_choice.push_back(1);}
                else{
                    wrong_answer+=1;
                    right_choice.push_back(0);}
                break;
            case 'd':
                if (vmcq[i].choice4==vmcq[i].right){
                    right_answer+=1;
                    quiz_choices_grade += 1 ;
                    right_choice.push_back(1);}
                else{
                    wrong_answer+=1;
                    right_choice.push_back(0);}
                break;
            };



            }

            total_quiz_grade += quiz_choices_grade ; /// for store quiz grade

            mcq_grades.push_back(right_answer);
    }

            ///-------------------------------------///

    void before_last_quize_details(vector<mcq> &template_mcq)
    {
        ///display details for quiz before the last quiz

        cout<<"**************************************\n";
        cout<<"details for quiz before the last quiz \n";
        cout<<"**************************************\n";

        if(number_of_quizes>1){

            for(int i=0 ; i<3;i++){

                cout<<"["<<i+1<<"]"<<template_mcq[template_mcq.size()-6+i].question<<"\n";
                cout<<"   "<<"[a]"<<template_mcq[template_mcq.size()-6+i].choice1<<"   "<<"[b]"<<template_mcq[template_mcq.size()-6+i].choice2<<"   "<<"[c]"<<template_mcq[template_mcq.size()-6+i].choice3<<"   "<<"[d]"<<template_mcq[template_mcq.size()-6+i].choice4<<"\n";
                cout<<"------------------------------\n";
                cout<<"your answer: "<<vcharacter[vcharacter.size()-6+i]<<"   ";

                if(right_choice[right_choice.size()-6+i] == 1 )
                    cout<<"      right answer\n";

                else
                    cout<<"      wrong answer\n";

                cout<<"right answer : "<<template_mcq[template_mcq.size()-6+i].right<<"\n";

                cout<<"your score : "<<right_choice[right_choice.size()-6+i]<<"\n";
}
}

    }

///-----------------------------------------------------------///

    void last_quize_details(vector<mcq> &template_mcq)
            {
                    ///display details for the last quiz

                cout<<"**************************************\n";
                cout<<"details for the last quiz \n";
                cout<<"**************************************\n";
                if(number_of_quizes>1){

            for(int i=0 ; i<3;i++){
                cout<<"["<<i+1<<"]"<<template_mcq[template_mcq.size()-3+i].question<<"\n";
                cout<<"   "<<"[a]"<<template_mcq[template_mcq.size()-3+i].choice1<<"   "<<"[b]"<<template_mcq[template_mcq.size()-3+i].choice2<<"   "<<"[c]"<<template_mcq[template_mcq.size()-3+i].choice3<<"   "<<"[d]"<<template_mcq[template_mcq.size()-3+i].choice4<<"\n";
                cout<<"------------------------------\n";
                cout<<"your answer: "<<vcharacter[vcharacter.size()-3+i]<<"   ";

                if(right_choice[right_choice.size()-3+i] == 1 )
                    cout<<"      right answer\n";
                else
                    cout<<"      wrong answer\n";

                cout<<"right answer : "<<template_mcq[template_mcq.size()-3+i].right<<"\n";
                cout<<"your score : "<<right_choice[right_choice.size()-3+i]<<"\n";

                                    }
                                    }
}
};

///**************************************************************************///

class complete
{
public:
    string question;
    string right;
    int quistion_id=id++;

public:
    void setinfo()
    {
        cout<<"enter the right answer:\n";
        cin>>right;
    }
    int operator == (complete x)
        {
            if(question==x.question)
                return 1;
            else
                return 0;
        }


        void view_all_question(vector<complete> &vcomplete)
        {
            cout<<"----------------------------------------------------\n";
            cout<<"complete Questions list (Total: "<< vcomplete.size() <<"Questions)\n";
            cout<<"----------------------------------------------------\n";
            for(int i=0;i<vcomplete.size();i++)
            {
                cout<<"["<<i+1<<"]"<<"(id = "<<vcomplete[i].quistion_id<<")"<<vcomplete[i].question<<"(Answer: "<<vcomplete[i].right<<")\n";

            }
            cout<<"----------------------------------------------------\n";
        }



         void start_new_quiz(vector<complete> &vcomplete,vector<complete> &template_complete)
        {
            srand(time(NULL)); //generates random seed val


            complete_rand= rand()% vcomplete.size();

            template_complete.push_back(vcomplete[complete_rand]);

            cout<<"[5]"<<vcomplete[complete_rand].question<<"\n";

            cin>>completeanswer;
            complete_answer.push_back(completeanswer);
            if(completeanswer==vcomplete[complete_rand].right){
                right_answer+=1;
                total_quiz_grade +=1 ;
                complete_grades.push_back(1);}
            else{
                wrong_answer+=1;
                complete_grades.push_back(0);}

            cout<<"number of right answers: "<<right_answer<<"\n";

            cout<<"number of wrong answers: "<<wrong_answer<<"\n";

            right_ans.push_back(right_answer);
            wrong_ans.push_back(wrong_answer);
            quizes_grades.push_back(total_quiz_grade);

            right_answer=0;
            wrong_answer=0;
            total_right+=right_answer;
            total_wrong+=wrong_answer;

        }
        ///------------------------------------------------------------///
        void before_last_quize_details(vector<complete> &template_complete)
        {
            cout<<"--------------------------------------\n";
            if(number_of_quizes>1){
                cout<<"[5]"<<template_complete[template_complete.size()-2].question<<"\n";
                cout<<"------------------------------\n";
                cout<<"your answer: "<<complete_answer[complete_answer.size()-2]<<"   ";

                if(complete_grades[complete_grades.size()-2] == 1 )
                    cout<<"      right answer\n";
                else
                    cout<<"      wrong answer\n";

                cout<<"right answer : "<<template_complete[template_complete.size()-2].right<<"\n";

                cout<<"your score : "<<complete_grades[complete_grades.size()-2]<<"\n";
                cout<<"your quiz score : "<<quizes_grades[quizes_grades.size()-2]<<"\n";
                            }

        }

///------------------------------------------------------------///

        void last_quize_details(vector<complete> &template_complete)
        {
            cout<<"--------------------------------------\n";
            if(number_of_quizes>1){
                cout<<"[5]"<<template_complete[template_complete.size()-1].question<<"\n";
                cout<<"------------------------------\n";
                cout<<"your answer: "<<complete_answer[complete_answer.size()-1]<<"   ";

                if(complete_grades[complete_grades.size()-1] == 1 )
                    cout<<"      right answer\n";
                else
                    cout<<"      wrong answer\n";

                cout<<"right answer : "<<template_complete[template_complete.size()-1].right<<"\n";

                cout<<"your score : "<<complete_grades[complete_grades.size()-1]<<"\n";
                cout<<"your quiz score : "<<quizes_grades[quizes_grades.size()-1]<<"\n";
                            }

        }

///---------------------------------------------------------------------------////

};
class tf
{
public:
    string question;
    string right;
    int quistion_id=id++;

public:
    void setinfo()
    {
        cout<<"enter the right answer:\n";
        cin>>right;
    }

    int operator == (tf x)
        {
            if(question==x.question)
                return 1;
            else
                return 0;
        }


        void view_all_question(vector<tf> &vtf)
        {
            cout<<"----------------------------------------------------\n";
            cout<<"TF Questions list (Total: "<< vtf.size() <<"Questions)\n";
            cout<<"----------------------------------------------------\n";
            for(int i=0;i<vtf.size();i++)
            {
                cout<<"["<<i+1<<"]"<<"(id = "<<vtf[i].quistion_id<<")"<<vtf[i].question<<"(Answer: "<<vtf[i].right<<")\n";
            }
        }

        void start_new_quiz(vector<tf> &vtf,vector<tf> &template_tf)
        {
            srand(time(NULL)); //generates random seed val


            b = rand()% vtf.size();
            template_tf.push_back(vtf[b]);

            cout<< "[4]" <<vtf[b].question<<"\n";

            cin>>tfanswer;
            tf_answer.push_back(tfanswer);
            if(tfanswer==vtf[b].right){
                right_answer+=1;
                total_quiz_grade += 1 ;
                tf_grades.push_back(1);}
            else{
                wrong_answer+=1;
                tf_grades.push_back(0);}

        }
///-----------------------------------------------------------------////
        void before_last_quize_details(vector<tf> &template_tf)
        {

            cout<<"--------------------------------------\n";
            if(number_of_quizes>1){
                cout<<"[4]"<<template_tf[template_tf.size()-2].question<<"\n";
                cout<<"------------------------------\n";
                cout<<"your answer: "<<tf_answer[tf_answer.size()-2]<<"   ";

                if(tf_grades[tf_grades.size()-2] == 1 )
                    cout<<"      right answer\n";
                else
                    cout<<"      wrong answer\n";

                cout<<"right answer : "<<template_tf[template_tf.size()-2].right<<"\n";

                cout<<"your score : "<<tf_grades[tf_grades.size()-2]<<"\n";
                            }

        }

///-----------------------------------------------------------------////

        void last_quize_details(vector<tf> &template_tf)
        {
            cout<<"--------------------------------------\n";
            if(number_of_quizes>1){
                cout<<"[4]"<<template_tf[template_tf.size()-1].question<<"\n";
                cout<<"------------------------------\n";
                cout<<"your answer: "<<tf_answer[tf_answer.size()-1]<<"   ";

                if(tf_grades[tf_grades.size()-1] == 1 )
                    cout<<"      right answer\n";
                else
                    cout<<"      wrong answer\n";

                cout<<"right answer : "<<template_tf[template_tf.size()-1].right<<"\n";

                cout<<"your score : "<<tf_grades[tf_grades.size()-1]<<"\n";
                            }
        }

};

///********************************************************************************************///

vector<mcq>vmcq;
vector<complete>vcomplete;
vector<tf>vtf;
vector<mcq>template_mcq;                 /// for keeping questions belong to before quiz
vector<complete>template_complete;       /// for keeping questions belong to before quiz
vector<tf>template_tf;                   /// for keeping questions belong to before quiz
mcq objmcq;
complete objcomplete;
tf objtf;

///****************************************************************************************************///

class player:public users
{
    public:
        string firstname="user";
        string lastname ="user";
        string username ="player";
        string password ="123";
        string role     ="player";
    public:

        void player_main_menue(vector<player> &players,vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete,vector<mcq> &template_mcq,vector<tf> &template_tf,vector<complete> &template_complete)
        {
                            cout<<"Welcome "<<players[keep].firstname<<" "<<players[keep].lastname <<"(PLAYER), please choose from the following options:\n";
                            cout<<"[1] Switch accounts\n[2] Update your name\n[3] Start a new quiz\n[4] Display your scores statistics\n";
                            cout<<"[5] Display all your scores\n[6] Display details of your last 2 quizzes\n[7] Exit the program\nMy choice: ";
                            cin >> mychoice ;
                            switch(mychoice)
                            {
                                case 1 :
                                    players[i].logout();

                                    break;

                                case 2 :
                                    players[i].rename(players,vmcq,vtf, vcomplete,template_mcq,template_tf,template_complete);break;

                        		case 3 :
                                        if(vmcq.size()<3 || vtf.size()<1  || vcomplete.size()<1 ){
                                            cout<<"you must add more question\n";
                                            player_main_menue(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);
                                        }

                                        objmcq.start_new_quiz(vmcq,template_mcq);

                                        objtf.start_new_quiz(vtf,template_tf);

                                        objcomplete.start_new_quiz(vcomplete,template_complete);

                                        break;

                        		case 4 :
                                        if(number_of_quizes<1){
                                            cout<<"you must take more quizes\n";
                                            player_main_menue(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);
                                        }

                                        players[i].display_scores_statistics(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);                      ///stat
                                        break;

                        		case 5 :
                                        if(number_of_quizes<1){
                                            cout<<"you must take more quizes\n";
                                            player_main_menue(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);
                                        }


                                        players[i].display_all_scores(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);
                                        break;


                        		case 6 :

                                        if(number_of_quizes<2){
                                            cout<<"you must take more quizes\n";
                                            player_main_menue(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);
                                        }

                                        objmcq.before_last_quize_details(template_mcq);            /// details for last 2 quizes
                                        objtf.before_last_quize_details(template_tf);
                                        objcomplete.before_last_quize_details(template_complete);

                                        objmcq.last_quize_details(template_mcq);            /// details for last 2 quizes
                                        objtf.last_quize_details(template_tf);
                                        objcomplete.last_quize_details(template_complete);
                                        break;


                        		case 7 :terminate();

                            };

        }


///--------------------------------------------------///

        void rename(vector<player> &players,vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete,vector<mcq> &template_mcq,vector<tf> &template_tf,vector<complete> &template_complete)
         {
             ///update name

             cout<<"enter your first name: ";
             cin>>fname;
             cout<<"enter your last  name: ";
             cin>>lname;
             firstname=fname;
             lastname =lname;
             cout<<"your new name: "<<fname+"  "+lname<<"\n";
             player_main_menue(players,vmcq,vtf, vcomplete,template_mcq,template_tf,template_complete);

         }

///--------------------------------------------------///

        int operator == (player x)
        {
            if(username==x.username)
                return 1;
            else
                return 0;
        }
///--------------------------------------------------///


        void setinfo()
        {
            cout<<"enter your first name : ";
            cin>>firstname;
            cout<<"enter your last  name : ";
            cin>>lastname;
            cout<<"enter your   password : ";
            cin>>password;
        }
///--------------------------------------------------///

        void display_all_scores(vector<player> &players,vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete,vector<mcq> &template_mcq,vector<tf> &template_tf,vector<complete> &template_complete)
            {
                cout<<"total number of quizes taken :\n"<<number_of_quizes;

                for(int i=0 ; i<right_ans.size(); i++){
                        cout<<"quiz "<<i+1<<":\n";
                        cout<<"number of right answers: "<<right_ans[i]<<"\n";
                        cout<<"number of wrong answers: "<<wrong_ans[i]<<"\n";
                        cout<<"your score : "<<right_ans[i]<<"\n";
                        cout<<"***************************************************\n";
                        player_main_menue(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);
                 }

            }


            ///--------------------------------///



            void display_scores_statistics(vector<player> &players,vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete,vector<mcq> &template_mcq,vector<tf> &template_tf,vector<complete> &template_complete)
            {
                cout<<"Your score statistics per quiz: \n";
                cout<<"     - Number of Quizzes taken: "<<number_of_quizes<<"\n";
                cout<<"     - Highest quiz score: "<<*max_element(right_ans.begin(), right_ans.end())<<"/5 \n";
                cout<<"     - Lowest quiz score : "<<*min_element(right_ans.begin(), right_ans.end())<<"/5 \n";
                cout<<"     - Average quiz score: "<<accumulate( right_ans.begin(), right_ans.end(), 0.0/ right_ans.size()) / right_ans.size()<<"/5 \n";
                cout<<"Your score statistics per question type: \n";
                cout<<"     - Number of MC questions: "<<number_of_quizes*3<<"\n";
                cout<<"     - Number of Complete questions: "<<number_of_quizes*1<<"\n";
                cout<<"     - Number of T/F Questions: "<<number_of_quizes*1<<"\n";
                cout<<"     - Average grade for MC questions: "<<accumulate( mcq_grades.begin(), mcq_grades.end(), 0.0/ mcq_grades.size()) / mcq_grades.size()<<"/3 \n";
                cout<<"     - Average grade for Complete questions: "<<accumulate( complete_grades.begin(), complete_grades.end(), 0.0/ complete_grades.size())/ complete_grades.size()<<"/1 \n";
                cout<<"     - Average grade for T/F questions: "<<accumulate( tf_grades.begin(), tf_grades.end(), 0.0/ tf_grades.size()) / tf_grades.size()<<"/1 \n";
                cout<<"Press [b] if you want to go back to the main menu or [e] to exit";
                cout<<"My choice: ";
                cin>>character;
                switch(character)
                {
                    case 'e':terminate();

                    case 'b':
                            player_main_menue(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);
                             break;
                };

            }
            ///-------------------------------------------///

};

///---------------------------------------------------------///


class Admin:public users
{
    public:

        string firstname="user";
        string lastname ="user";
        string username ="admin";
        string password ="123";
        string role     ="admin";


    public:

        void admin_main_menue(vector<Admin> &objs,vector<player> &players,vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete)
        {
                                cout<<"Welcome "<<objs[keep].firstname<<" "<<objs[keep].lastname <<"(ADMIN), please choose from the following options:\n";
                                cout<<"[1] Switch accounts\n[2] Update your name\n[3] View all users\n[4] Add new user\n";
                                cout<<"[5] View all questions\n[6] Add new question\n[7] Load questions from file\n[8] Exit the program\nMy choice: ";
                                cin >> mychoice ;
                                switch(mychoice)
                                {
                                    case 1 :
                                            objs[i].logout();
                                            ///return main();
                                            break;

                                    case 2 :					//update name
                                            objs[i].rename(objs,players,vmcq,vtf,vcomplete);
                                            break;
                                    case 3 :
                                        					//view all user
                                        objs[i].print_all_users(objs,players,vmcq,vtf,vcomplete);

                                        break;


                                    case 4:///modify
                                        ///---------------------------------///
                                        objs[i].add_new_user(objs,players);
                                        objs[i].admin_main_menue(objs,players,vmcq,vtf,vcomplete);
                                        break;
                                        ///------------------------------------///

                                    case 5: //view all question
                                        ///---------------------///
                                        objs[i].view_all_question(objs,players,vmcq,vtf,vcomplete);
                                        break;
                                        ///----------------------///

                                    case 6:  //add new question
                                        ///--------------------------------///
                                        objs[i].add_new_quistion(objs,players,vmcq,vtf,vcomplete);
                                        break;
                                        ///---------------------------------///

                                    case 7:
                                        objs[i].load_from_file(objs,players,vmcq,vtf,vcomplete);
                                                        //read from file
                                        break;


                                    case 8 :terminate();//abort();
                                };

        }

///--------------------------------------------------------------------///


        void rename(vector<Admin> &objs,vector<player> &players,vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete)
         {
             cout<<"enter your first name: ";
             cin>>fname;
             cout<<"enter your last  name: ";
             cin>>lname;
             firstname=fname;
             lastname =lname;
             cout<<"your new name: "<<fname+"  "+lname<<"\n";
             admin_main_menue(objs,players,vmcq,vtf,vcomplete);
         }

///--------------------------------------------///
        int operator == (Admin x)
        {
            if(username==x.username)
                return 1;
            else
                return 0;
        }

///--------------------------------------------///

        void print_all_users(vector<Admin> &objs,vector<player> &players,vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete) // need to make vectors are global
        {
            cout<<"Existig users in system:\n";
            cout<<"First name  Last name  Username    Role\n";
            for(int i=0;i<objs.size();i++)
            {
                cout<<objs[i].firstname<<"        "<<objs[i].lastname<<"        "<<objs[i].username<<"      "<<objs[i].role<<"\n";
            }

            for(int i=0;i<players.size();i++)
            {
                cout<<players[i].firstname<<"        "<<players[i].lastname<<"        "<<players[i].username<<"      "<<players[i].role<<"\n";
            }
            cout<<"Press [n] if you want to add a new user or [b] to go back to the main menu./n";

            while(true){
            cin>>view_all_users_answer;
            switch(view_all_users_answer)
            {
            case 'n':
                add_new_user(objs, players);
                admin_main_menue(objs,players,vmcq,vtf,vcomplete);
                break;
            case 'b':
                admin_main_menue(objs,players,vmcq,vtf,vcomplete);
                break;
            default:
                cout<<"please enter [n] or [b] only\n";continue;
            };
            break;
            }

        }





///--------------------------------------------///




        void setinfo()
        {
            cout<<"enter your first name : ";
            cin>>firstname;
            cout<<"enter your last  name : ";
            cin>>lastname;
            cout<<"enter your   password : ";
            cin>>password;
        }

///--------------------------------------------///

        void load_from_file(vector<Admin> &objs,vector<player> &players,vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete)
        {
            int j=0;
            string f;

            fstream fin;
            cout<<"enter file name: ";
            cin>>f;
            f+=".txt";


            fin.open(f.c_str()); /// .c_str function to turn string into c-string.
            string str;

            if(!fin) {
                cerr << "Unable to open " << f << endl;
                load_from_file(objs,players,vmcq,vtf,vcomplete);
                    }


            while (getline(fin, str))
            {


                if(j==0){
                    if(str=="MCQ"){
                        j=1;
                        continue;}

                    else if(str=="COMPLETE"){
                        j=6;
                        continue;}
                    else if(str=="TF"){
                        j=8;
                        continue;}
                    else{
                        cout<<"**********************error happen****************************\n";
                        view_all_question(objs,players,vmcq,vtf,vcomplete);
                        return;

                    }
                }




                if (j==1){


                    for(int j=0;j<vmcq.size();j++){
                        if(vmcq[j].question == str){
                            cout<<"***************repeated status******************\n";
                            view_all_question(objs,players,vmcq,vtf,vcomplete);
                            return;////////----------->>>>>>>>>>>>>>>>>.
                        }

                    }


                    mcq m;
                    m.question=str;
                    j+=1;
                    vmcq.push_back(m);
                }
                else if(j==2){
                    vmcq[vmcq.size()-1].choice1=str;
                    vmcq[vmcq.size()-1].right=str;
                    j+=1;
                }

                else if(j==3){
                    vmcq[vmcq.size()-1].choice2=str;
                    j+=1;
                }

                else if(j==4){
                    vmcq[vmcq.size()-1].choice3=str;
                    j+=1;
                }

                else if(j==5){
                    vmcq[vmcq.size()-1].choice4=str;
                    j=0;
                }

                else if(j==6){

                    for(int j=0;j<vcomplete.size();j++){

                        if(vcomplete[j].question == str){
                            cout<<"***************repeated status******************\n";
                            view_all_question(objs,players,vmcq,vtf,vcomplete);
                            return;
                        }}

                    complete c;
                    c.question=str;
                    j+=1;
                    vcomplete.push_back(c);
                }

                else if(j==7){

                    if(str.empty()){
                        cout<<"**********************error happen****************************\n";
                        view_all_question(objs,players,vmcq,vtf,vcomplete);
                        return;                    }

                    else{
                    vcomplete[vcomplete.size()-1].right=str;
                    j=0;
                    }
                }

                else if(j==8){

                    for(int j=0;j<vtf.size();j++){

                        if(vtf[j].question == str){
                            cout<<"***************repeated status******************\n";
                            view_all_question(objs,players,vmcq,vtf,vcomplete);
                            return;
                        }
                        }

                    tf t;
                    t.question=str;
                    j+=1;
                    vtf.push_back(t);
                }

                else if(j==9){
                    if (str=="true"||str=="false"){

                        vtf[vtf.size()-1].right=str;
                        j=0;
                    }
                    else{
                        cout<<"**********************error happen****************************\n";
                        view_all_question(objs,players,vmcq,vtf,vcomplete);

                        }
                }


            }
            cout<<"****************\nfile was read\n****************\n";

            view_all_question(objs,players,vmcq,vtf,vcomplete);



        }

///------------------------------------------------------------///


        void show()
        {

            cout<<"Press [d] and the question ID if you want to delete a question (Example: d 2)\n";
            cout<<"press [b] if you want to go back to main menue\n";

        }

///--------------------------------------------///

        void view_all_question(vector<Admin> &objs, vector<player> &players, vector<mcq> &vmcq,vector<tf> &vtf,vector<complete> &vcomplete)  // without randomization
        {

                                        cout<<"Number of questions available: "<< vmcq.size() + vtf.size() + vcomplete.size()<<"\n";
                                        cout<<"---------------------------------------------------\n";
                                        objmcq.view_all_question(vmcq);
                                        objtf.view_all_question(vtf);
                                        objcomplete.view_all_question(vcomplete);
                                        show();
                                        cout<<"---------------------------------------------------\n";
                                        while(true){
                                        cin>>character;
                                        switch(character)
                                        {
                                            case 'b':
                                                admin_main_menue(objs,players,vmcq,vtf,vcomplete);

                                                break;


                                            case 'd':{
                                                        vector<int> concat_id;
                                                         for(int j=0 ;j<vmcq.size();j++)
                                                            concat_id.push_back(vmcq[j].quistion_id);



                                                        for(int j=0 ;j<vtf.size();j++)
                                                            concat_id.push_back(vtf[j].quistion_id);




                                                        for(int j=0 ;j<vcomplete.size();j++)
                                                            concat_id.push_back(vcomplete[j].quistion_id);


                                                        cin>>g;


                                                        if( g > *max_element(concat_id.begin(), concat_id.end()) || g < 3)
                                                            {
                                                                cout<<"invalid\n";
                                                                continue;
                                                            }


                                                        else{

                                                                for(int j=0 ;j<vmcq.size();j++){

                                                                    if(g == vmcq[j].quistion_id)
                                                                        vmcq.erase(vmcq.begin() + j );
                                                                }

                                                                for(int j=0 ;j<vtf.size();j++){

                                                                    if(g == vtf[j].quistion_id)
                                                                        vtf.erase(vtf.begin() + j );
                                                                }

                                                                for(int j=0 ;j<vcomplete.size();j++){

                                                                    if(g == vcomplete[j].quistion_id)
                                                                        vcomplete.erase(vcomplete.begin() + j  );
                                                                    }


                                                                view_all_question(objs, players, vmcq, vtf, vcomplete);
                                                        }
                                                    }
                                                  break;     ///for switch case

                                            default:cout<<"invalid\n";continue;
                                        };

                                        break;   /// for infinite loop
                                        }


        }



///--------------------------------------------///


        void add_new_user(vector<Admin> &objs,vector<player> &players)
        {
            while(true){
                        cout<<"admin or player: ";
                        cin>>uname;
                        if(uname=="admin")
                        {
                            Admin v;
                            cout<<"enter your username: ";
                            cin>>v.username;
                            for(int i=0;i<objs.size();i++)
                            {
                                if(v==objs[i])
                                {
                                    cout<<"invalid";
                                    break;
                                }
                                else if(i==(objs.size())-1)
                                {
                                    counter+=1;
                                    v.setinfo();
                                    objs.push_back(v);
                                    break;
                                }
                            }
                        }
                        else if(uname=="player")
                         {
                            player v;
                            cout<<"enter your username: ";
                            cin>>v.username;
                            for(int i=0;i<players.size();i++)
                            {
                                if(v==players[i])
                                {
                                    cout<<"invalid\n";
                                    break;
                                }
                                else if(i==(players.size())-1)
                                {
                                    counter+=1;
                                    v.setinfo();
                                    players.push_back(v);
                                    break;
                                }
                            }
                        }

                        if (  counter==2 )
                            {
                                counter-=1;
                                break;
                            }
                        }
        }

///-------------------------------------------------------////
        void add_new_quistion( vector<Admin> &objs,vector<player> &players,vector<mcq> &vmcq,vector<tf> vtf ,vector<complete> &vcomplete)
        {
                                        cout<<"mcq or complete or tf :\n";

                                        cin>>uname;

                                        if(uname=="mcq")
                                        {

                                            mcq m;
                                            while(true)
                                            {

                                            cout<<"enter the question:\n";
                                            cin>>m.question;

                                            if(vmcq.size()==0)
                                            {
                                                m.setinfo();
                                                vmcq.push_back(m);
                                                view_all_question(objs,players,vmcq,vtf,vcomplete);
                                                break;
                                            }
                                            /// compare with operator overloading
                                            else
                                            {
                                                for(int i=0;i<vmcq.size();i++)
                                                {
                                                    if(m.question == vmcq[i].question)
                                                    {
                                                        cout<<"invalid\n";
                                                        break;
                                                    }

                                                    else if(i==(vmcq.size())-1)
                                                    {
                                                        counter+=1;
                                                        m.setinfo();
                                                        vmcq.push_back(m);
                                                        view_all_question(objs,players,vmcq,vtf,vcomplete);
                                                        break;
                                                    }

                                                }
                                            }
                                            if(counter==2)
                                            {
                                                counter-=1;
                                                break;
                                            }}}
                                        //----------------------//
                                        else if(uname=="complete")
                                        {


                                            complete c;
                                            while(true)
                                            {
                                            cout<<"enter the question:\n";
                                            cin>>c.question;
                                            if(vcomplete.size()==0)
                                            {
                                                c.setinfo();
                                                vcomplete.push_back(c);
                                                view_all_question(objs,players,vmcq,vtf,vcomplete);
                                                break;
                                            }
                                            else
                                            {
                                                 /// compare with operator overloading
                                                for(int i=0;i<vcomplete.size();i++)
                                                {
                                                    if(c.question==vcomplete[i].question)
                                                    {
                                                        cout<<"invalid\n";
                                                        break;
                                                    }
                                                    else if(i==(vcomplete.size())-1)
                                                    {
                                                        counter+=1;
                                                        c.setinfo();
                                                        vcomplete.push_back(c);
                                                        view_all_question(objs,players,vmcq,vtf,vcomplete);
                                                        break;
                                                    }
                                                }
                                            }
                                            if(counter==2)
                                            {
                                                counter-=1;
                                                break;
                                            }}}
                                            //-----------------------------------//
                                        else if(uname=="tf")
                                        {
                                            tf t;
                                            while(true)
                                            {
                                            cout<<"enter the question:\n";
                                            cin>>t.question;
                                            if(vtf.size()==0)
                                            {
                                                t.setinfo();
                                                vtf.push_back(t);
                                                view_all_question(objs,players,vmcq,vtf,vcomplete);
                                                break;
                                            }


                                            else
                                            {
                                                for(int i=0;i<vtf.size();i++)
                                                {
                                                    if(t.question == vtf[i].question)
                                                    {
                                                        cout<<"invalid\n";
                                                        break;
                                                    }
                                                    else if(i==(vtf.size())-1)
                                                    {
                                                        counter+=1;
                                                        t.setinfo();
                                                        vtf.push_back(t);
                                                        view_all_question(objs,players,vmcq,vtf,vcomplete);
                                                        break;
                                                    }
                                                }
                                            }
                                            if(counter==2)
                                            {
                                                counter-=1;
                                                break;
                                            }}}

                                        else{
                                            cout<<"invalid\nplease enter mcq or complete or tf only \n";
                                            add_new_quistion(objs,players,vmcq,vtf,vcomplete);
                                        }
        }

};


///--------------------------------------------------------///
vector<Admin>objs;
vector<player>players;
Admin obj1;
player obj2;

///--------------------------------------------///

int main()
{
    objs.push_back(obj1);
    players.push_back(obj2);

    counter=0;
	//	(main menue)

	cout<<"*******************************************************************\n";
	cout<<"Welcome to the Quiz game program V2.0!\n";
	cout<<"*******************************************************************\n";



	while(true)
	{
		cout<<"Please enter your username: ";
		cin>>uname;
		cout<<"Please enter your password: ";
		cin>>pword;


	  ///    loop on admins

		for( i=0;i<objs.size();i++)
		{
			keep=i;
			if(objs[i].username==uname)
				{
				    counter+=1;
					if(objs[i].password==pword)

						{
								objs[i].admin_main_menue(objs,players,vmcq,vtf,vcomplete);
						}


					else
						cout<<"wrong username or password\n";break;
				}
		}




		if(counter==1)
        {
            counter=0;
            continue;
        }




        else
        {            ///loop on players

		for( i=0;i<players.size();i++)
		{
			keep=i;
			if(players[i].username==uname)
				{
					if(players[i].password==pword)

						{
						    players[i].player_main_menue(players,vmcq,vtf,vcomplete,template_mcq,template_tf,template_complete);
						}
					else
						cout<<"wrong username or password\n";break;
				}
			else if(i==(players.size())-1)
				{
					cout<<"wrong username or password\n";
					break;
				}
		}
	}
	}
	return 0;
}
