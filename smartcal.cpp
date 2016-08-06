input: array(3~5), target


string smartCal(int target, vector<int> nums){
	//corner
	if(nums.empty()) return;
	if(nums.size() == 1 && nums[0] != target) return;
	if(nums.size() == 1 && nums[0] == target) return to_string(nums[0]);

	//
	string res;
	int length = nums.size(); 
	vector<bool> ifNumUsed(length, false);
	
	for(int i = 0; i < length; ++i){
		
	}
}



 
// // Driver program
// int main()
// {
//     string expr = "1*2+3*4";
//     int len = expr.length();
//     vector<int> ans = evaluateAll(expr, 0, len-1);
 
//     for (int i=0; i< ans.size(); i++)
//         cout << ans[i] << endl;
 
//     return 0;
// }