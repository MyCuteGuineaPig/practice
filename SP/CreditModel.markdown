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
