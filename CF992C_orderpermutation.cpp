#include <bits/stdc++.h>
using namespace std;
 
// Define constants
const int MAX_POW = 40;
const long long INF = 1e15;
 
// Struct to represent tasks
struct Task {
    enum TaskType { RANGE, PRINT_AFTER } type;
    // For RANGE tasks
    long long l, r, k;
    // For PRINT_AFTER tasks
    int val;
 
    // Constructor for RANGE task
    Task(long long l_, long long r_, long long k_) : type(RANGE), l(l_), r(r_), k(k_), val(0) {}
 
    // Constructor for PRINT_AFTER task
    Task(int v) : type(PRINT_AFTER), l(0), r(0), k(0), val(v) {}
};
 
// Function to compute half interval count
long long half_interval_count(long long length, const vector<long long>& pow2) {
    if (length <= 1)
        return 1;
    if ((length - 1) <= MAX_POW)
        return pow2[length - 1];
    else
        return INF;
}
 
int main(){
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    // Precompute powers of two up to 2^40
    vector<long long> pow2(MAX_POW + 1, 1);
    for(int i = 1; i <= MAX_POW; ++i){
        pow2[i] = pow2[i-1] * 2;
    }
 
    // Read number of test cases
    long long t;
    cin >> t;
 
    // Prepare output buffer
    string output;
 
    while(t--){
        long long n, k;
        cin >> n >> k;
 
        if(n == 1){
            if(k == 1){
                output += "1 \n";
            }
            else{
                output += "-1\n";
            }
            continue;
        }
 
        // Compute total_count
        long long total_count = half_interval_count(n, pow2);
        if(k > total_count){
            output += "-1\n";
            continue;
        }
 
        // Initialize stack with the initial RANGE task
        vector<Task> stack_tasks;
        stack_tasks.emplace_back(n >= 1 ? Task(1, n, k) : Task(1, n, k));
 
        // Initialize result vector
        vector<int> result;
 
        while(!stack_tasks.empty()){
            Task current = stack_tasks.back();
            stack_tasks.pop_back();
 
            if(current.type == Task::PRINT_AFTER){
                // PRINT_AFTER task: append the value to result
                result.push_back(current.val);
            }
            else{
                // RANGE task: process the range [l, r] with current_k
                long long l = current.l;
                long long r = current.r;
                long long cur_k = current.k;
 
                while(true){
                    if(l == r){
                        // Base case: single element
                        result.push_back(static_cast<int>(l));
                        break;
                    }
 
                    long long length = r - l;
                    long long half = half_interval_count(length, pow2);
 
                    if(cur_k <= half){
                        // First half: append l and move forward
                        result.push_back(static_cast<int>(l));
                        l += 1;
                    }
                    else{
                        // Second half: schedule PRINT_AFTER for l and process subproblem
                        stack_tasks.emplace_back(static_cast<int>(l));
                        l += 1;
                        cur_k -= half;
                        continue;
                    }
 
                    // Check if we've exceeded the range
                    if(l > r){
                        break;
                    }
 
                    if(l == r){
                        result.push_back(static_cast<int>(l));
                        break;
                    }
                }
            }
        }
 
        // Convert result vector to string
        string res_str;
        for(auto num : result){
            res_str += to_string(num) + " ";
        }
        res_str += "\n";
        output += res_str;
    }
 
    cout << output;
    return 0;
}
