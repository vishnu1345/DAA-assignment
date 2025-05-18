#include<iostream>
using namespace std;

struct Activity{
    int start , finish;
};

bool compare(Activity a , Activity b){
    return a.finish<b.finish;
}

void activityselection(vector<int> start , vector<int> finish){
    int n = start.size();

    vector<Activity> activities(n);

    for(int i =0;i<n;i++){
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }

    sort(activities.begin() , activities.end() , compare);

    int count = 1;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")" << endl;
    int lastfinish = activities[0].finish;

    for(int i =1;i<n;i++){
        if(activities[i].start >= lastfinish){
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")" << endl;
            lastfinish = activities[i].finish;
            count++;
        }
    }

    cout << "Maximum number of non-overlapping activities: " << count << endl;

}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    activityselection(start, finish);
    return 0;
}