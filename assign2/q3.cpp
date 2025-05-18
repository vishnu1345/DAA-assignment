#include<iostream>
using namespace std;

struct Job{
    int id , deadline , profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void solve(vector<int> profit , vector<int> deadline){
    int n = profit.size();

    vector<Job> jobs(n);

    for(int i =0;i<n;i++){
        jobs[i].id = i+1;
        jobs[i].profit = profit[i];
        jobs[i].deadline = deadline[i];
    }

    sort(jobs.begin() , jobs.end() , compare);

    int maxDeadline = 0;
    for (auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> slot(maxDeadline+1 , -1);


    int total = 0;
    int count = 0;

    for(int i=0;i<n;i++){
        for(int j = jobs[i].deadline;j>0;j--){
            if(slot[j]==-1){
                slot[j] = jobs[i].id;
                total += jobs[i].profit;
                count++;
                cout << "Job" << jobs[i].id << " ";
                break;
            }
        }
    }

    cout << "\nTotal Jobs Done: " << count << endl;
    cout << "Total Profit: " << total << endl;
}

int main(){
    vector<int> profit = {20, 10, 40, 30};
    vector<int> deadline = {4, 1, 1, 1};

    solve(profit, deadline);

    return 0;
}