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

比如 k = 18, 把所有数据分成18分，每一份80% train, 20%test, 每一个train 都是独立的，比如train完第一份 然后test, 然后不会在train 完第一份基础上,  独立train 完第二份 然后test. 

用的评判标准是用match ratio or likelihood 


#### Greedy Forward

First choose the best variable, together with optimal vector Beta, out of all possible candidate variable based on out-of-sample likelihood. Then fix first chosen variable, add another variable out of the remaining, and choose the best pair, together with their optimal vector betas. Follow this procedure until we choose tan amount of statistically significant variables, while stoping short of over-fitting the model.

The criterion that is applied when chooing how many variables to use AIC(AKaike Information Criterion). AIC provides a means for comparing models. Given data set, several candidate models with different nuber of variables may be ranked according to their AIC, with the model that has the maximum AIC being the best. AIC = 2ln(L) = 2k where is number of parameters, L is the likihood of the model. Thus a model is penalized as the number of parameters used in the model increases.

用Greedy Forward 来选取变量, AIC 作为标准, 选取变量是用所有数据，比如k-Fold Out-of-Sample 分为18份, 选择变量用所有的18份来选取

#### Other Consideration

avoid choosing those variables that show much co-movement or are highly correlated. This is for a statistical reason: model with correlated variables tend to be unstable and tend to underperform on out of sample data. As a result, we group these variables into different categories like profitablility, liquidity, efficiency, coverage ratios and strive to choose variables from different groups.



#### Regularization 


1. The model has large number of parameters relative to number of observed training records. This happen when few observation than number of model parameters
2. explanatory variables may be highly correlated. 

In either case, maximum likelihood estimation might produce overfitting, good in-sample likelihood, but do not generalize well to out-of-sample data. To avoid such over-fitting problems, we adopt commonly used practice known as L2 regularization. 

Specifically, to fit the models in CreditModel, we find Beta that maximize the following modified likelihood function $$ \left( l \left( \beta \right) \right) - \lambda \sum_k \beta_k^2 $$

where $$\lambda$$ is a model hyper-parameter that controls the balance between log-likelihood function and regularization term $$\sum \beta_k^2 $$ (can also be interpreted as penalizing parameters with large magnitude.)

We find the best $$\lambda$$ using a binary search based on fivefold cross validation on out-of-sample likelihood. We search a pre-specified list of  $$\lambda$$ candidates to find the one whose out-of-sample modfied likelihood is maximized. after we find the best $$\lambda$$, we set the final model parameters to be the associated $$\beta$$

The parameter $$\lambda$$is part of likelihood that is being maximized and influences the choice of the optimal betas, it does not appear in the final formula, $$\lambda$$ 不用于最后的计算credit score, 只用于train model


先选取变量, 然后带着regularization 看哪个weight 最后，用所有train data带着










