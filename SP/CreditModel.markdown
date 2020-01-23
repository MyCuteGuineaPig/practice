## Purpose and Scope of CreditModels

**Model Output**: <span style="color:red">**lower-case**</span> letter grade symbols

**Scoring models**: reflect the observed historical relationship between key financial data of rated and 
unrated companies in a particular industry and their Standard & Poor's rating services ("S&P") or othter private assessment of credits
, containing more than 10 years of company financials

The models are based on the **Exponential Density Model**, where the probability distribution of score grades takes an exponential form, 
providing detailed information and insight about the credit risk of firm, including estimates of the probability of each possible credit
score, including those not historically observed for that type of firm

Note that credit scores reflect the <span style="color:red"> **standalone credit risk** of a company</span>. Therefore, they do not incorporate the benefits 
or burdens of affiliation, such as support from a parent company or government, or the integration into a holding structure.

CreditModel is effective for publicly traded and privately owned corporate with revenuse above 50 million usd or 10 billion JPY. 


#### Reason for Rank Transformation


ensure a robous treatment of outliers. To implement rank transformation, using the empirical distribution of the observerd data to transform raw data into standardized variable between 0 and , while keeping the relative rank order the same. Using untransformed financial ratios often results in an underperforming model because the final model is too influenced by outliers and by flawed observations.


#### K-FOLD Out-of-Sample 

To prevent overfitting, model variables and parameter values are first determined by maximizing the likelihood function on a subset of data. Then resulting model's performance is re-evaluated on remaining data set. **K-fold Out-Of-Sample method divides the data set into k separate subsets and the model is fitted and re-ecaluated k times**, with each respective fitting and re-evaluation being associated with one of the subsets and its complement, which is the remainder of the data set.

Finally, all re-evaluations of the out-of-sample evaluted likelihood functions are averaged to obtain an out-of-sample likelihood value. This average out of sample likelihood vlaue for may then be compared to the average out-of-sample likelihood value for other models to see which is better.
