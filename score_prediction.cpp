#include<iostream>
using std::cout;
using std::cin;

int projectScore(int left_over, int runRate) {
    int project_score = left_over * runRate;
return project_score;
}

int projectScore2(int left_over, int runRate) {
    int project_score = left_over * runRate;
    return project_score;
}
int projectScore3(int left_over, int runRate) {
    int project_score = left_over * runRate;
    return project_score;
}

int main() {
    int total_run;
    float over;
    float runRate;
    cout << "Current Total Score : ";
    cin >> total_run;
    cout << "Current Run-rate : ";
    cin >> runRate;
    cout << "Current over : ";
    cin >> over;
    cout << std::endl;

    int N_over = (int)over*10;
    int total_balls = 120;
    int newOver = ((int)over * 6) + (N_over) % 10;
    int total_over = 20;
    int left_balls = total_balls - newOver;
    float left_over = left_balls/6;
    // cout << left_balls << " "<< left_over << " "<<((int)over * 6) + (N_over) % 10<< " "<< std::endl;
    cout <<"Project score in upcoming "<<left_over<< " over with run-rate "<< runRate << " is : "<< projectScore(left_over,runRate) + total_run << std::endl;
    cout <<"Project score in upcoming "<<left_over<< " over with run-rate "<< runRate+2 << " is : "<< projectScore2(left_over,runRate+2) + total_run << std::endl;
    cout <<"Project score in upcoming "<<left_over<< " over with run-rate "<< runRate+3 << " is : "<< projectScore3(left_over,runRate+3) + total_run << std::endl;

}