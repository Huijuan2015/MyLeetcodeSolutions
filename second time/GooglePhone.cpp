1.
input: a string
output: use that string to construct the longest palindrome (may have many output)

EX: abccccdd => ccdadcc 
---------------------------------
2.
input: tree edges
output: print the tree

EX: 0->1, 1->2, 0->3, 3->4, 1->5
print 0 1 2 5 3 4 (pre-order)
because tree is like this
   0
  /  \
1    3 
/ \   /
2 5 4
---------------------------------

LC 381
---------------------------------
高精度加法，用数组代替单独的整数
---------------------------------
删除二叉树一些节点，返回剩下的森林。我的解法是用dfs遍历整个树，遇到需要删除的节点就删除，将子结点作为新的数的树根，父节点指向该节点的指针设为NULL。
---------------------------------
nput一个string str，方法要求split str into elements，return符合要求的最大elements数量。。这题有点怪我来写几个例子：
eg1. input: abab －》 return 2
         可以被分成 ab ｜ ab， 这样子[ab][ab]是对称的；
         但是不能分成 a | b | a | b, 因为[a][a]不对称。
eg2.input: teammate －》 return 6 鏉ユ簮涓€浜�.涓夊垎鍦拌鍧�. 
        可以被分成 te | a | m | m | a | te, [te][a][m][m][a][te]是对称的
eg3: input: ab －》 return 1
        [ab], 这直接是1
eg4: input: aaa -> reurn 3
       这个可以分成 a｜a｜a 或者直接不分： aaa。 但题目要求返回最大可能值，所以是3
eg5: 空字符串返回0
---------------------------------
给一个unsorted array, for all a[i] <= a[j] 找出 j - i 最大的值。。。O(N) time O(N) Space
因为时间不多了加上也有点紧张。。没想出什么好办法。 后来他给了HINT说要开一个数组存smallest so far 然后我大概想了一会
开一个n长度的array, 从左往右每个位置存到目前位置的smallest number. 存完后从数组最右往左遍历 记录结果max, 如果a[right] > small[right - max - 1] 更新max = max + 1.鐣欏璁哄潧-涓€浜�-涓夊垎鍦�
如果发现a[right] <= smallest[right - max - 1] 说明，a[right] 比这之前的都小，就right--继续遍历。。。 直到right <= max。。。。

    public int findMaximumGap(int[] nums){
        // Invalid
        if (nums == null || nums.length == 0) return 0;
        int[] smallestSoFar = new int[nums.length];
        smallestSoFar[0] = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            smallestSoFar[i] = (nums[i] < smallestSoFar[i - 1]) ? nums[i] : smallestSoFar[nums.length - 1];
        }
        int max = 0;
        for (int j = nums.length - 1; j > max; j--){
            while ((j > max) && (nums[j] >= smallestSoFar[j - max - 1])) {
                ++max;
            }
        }
        return max;
    }
    http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
---------------------------------
给一个tree，每一个treeNode多2个指针pre next但是是空的。要求按inorder的顺序把指针连起来。
Lz用recursion。写的不好。
followup是怎么实现insert方法。还问了时间复杂度和空间复杂度。
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=192582&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3090%5D%5Bvalue%5D%3D1%26searchoption%5B3090%5D%5Btype%5D%3Dradio%26searchoption%5B3046%5D%5Bvalue%5D%3D1%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
---------------------------------
---------------------------------
