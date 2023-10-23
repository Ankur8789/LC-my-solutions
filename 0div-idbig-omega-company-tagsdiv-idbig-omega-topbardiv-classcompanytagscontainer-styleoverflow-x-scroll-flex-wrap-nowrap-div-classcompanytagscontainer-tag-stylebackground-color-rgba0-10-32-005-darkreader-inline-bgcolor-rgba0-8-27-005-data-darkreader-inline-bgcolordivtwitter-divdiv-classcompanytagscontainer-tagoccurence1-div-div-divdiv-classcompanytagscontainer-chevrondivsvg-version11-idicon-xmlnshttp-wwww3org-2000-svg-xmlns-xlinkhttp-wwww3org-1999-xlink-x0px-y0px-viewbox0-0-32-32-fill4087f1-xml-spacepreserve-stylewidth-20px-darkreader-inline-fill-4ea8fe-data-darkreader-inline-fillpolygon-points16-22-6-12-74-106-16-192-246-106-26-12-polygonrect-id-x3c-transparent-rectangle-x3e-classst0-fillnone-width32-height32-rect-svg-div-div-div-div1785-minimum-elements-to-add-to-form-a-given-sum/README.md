<h2><a href="https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 27, 0.05);" data-darkreader-inline-bgcolor=""><div>Twitter</div><div class="companyTagsContainer--tagOccurence">1</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4ea8fe;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1785. Minimum Elements to Add to Form a Given Sum</a></h2><h3>Medium</h3><hr><div><p>You are given an integer array <code>nums</code> and two integers <code>limit</code> and <code>goal</code>. The array <code>nums</code> has an interesting property that <code>abs(nums[i]) &lt;= limit</code>.</p>

<p>Return <em>the minimum number of elements you need to add to make the sum of the array equal to </em><code>goal</code>. The array must maintain its property that <code>abs(nums[i]) &lt;= limit</code>.</p>

<p>Note that <code>abs(x)</code> equals <code>x</code> if <code>x &gt;= 0</code>, and <code>-x</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,-1,1], limit = 3, goal = -4
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can add -2 and -3, then the sum of the array will be 1 - 1 + 1 - 2 - 3 = -4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,-10,9,1], limit = 100, goal = 0
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 10<sup>6</sup></code></li>
	<li><code>-limit &lt;= nums[i] &lt;= limit</code></li>
	<li><code>-10<sup>9</sup> &lt;= goal &lt;= 10<sup>9</sup></code></li>
</ul>
</div>