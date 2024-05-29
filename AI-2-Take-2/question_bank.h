#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class weightedQuestion {
  public:
    string question;
    vector<vector<float>> weights = {
      {{}, {}, {}, {}}, {{}, {}, {}, {}}, {{}, {}, {}, {}}};

  public:
    weightedQuestion(string q, vector<vector<float>> w) {
      question = q;
      weights = w;
    };

  public:
    vector<vector<float>> returnScores(string answer) {
      if (answer == "A") {
        return weights[0];
      } else if (answer == "B"){
        return weights[1];
      }else if (answer == "C"){
        return weights[2];
      } else {
        cout<< "Invalid answer\n";
        return {{0,0,0,0}};
      }
    };
};


// Initialising the weighted questions
string q1 =
    "Economic Policy:\na) Support for free-market capitalism\nb) Advocacy for "
    "regulated capitalism\nc) Prefer a socialist economic model";
weightedQuestion w1 =
    weightedQuestion(q1, {{0, 1, 2, 0}, {2, 1, 0, 2}, {1, 0, 0, 1}});

string q2 = "Immigration:\na) Support stricter immigration policies\nb) Favor "
            "a balanced and humane approach\nc) Advocate for open borders";
weightedQuestion w2 =
    weightedQuestion(q2, {{0, 2, 1, 0}, {2, 1, 1, 2}, {1, 0, 1, 1}});

string q3 =
    "Healthcare:\na) Support a free-market healthcare system\nb) Advocate for "
    "a public option\nc) Prefer a fully government-run healthcare system";
weightedQuestion w3 =
    weightedQuestion(q3, {{0, 2, 2, 0}, {2, 0, 0, 1}, {1, 0, 0, 2}});

string q4 = "Climate Change:\na) Climate change is a serious threat and urgent "
            "action is needed\nb) Acknowledge climate change but prioritize "
            "economic considerations\nc) Deny or downplay the impact of human "
            "activity on climate change";
weightedQuestion w4 =
    weightedQuestion(q4, {{1, 0, 1, 3}, {1, 2, 1, 1}, {0, 1, 0, 0}});

string q5 =
    "Gun Control:\na) Support stricter gun control measures\nb) Advocate for "
    "maintaining current regulations\nc) Oppose most forms of gun control";
weightedQuestion w5 =
    weightedQuestion(q5, {{2, 0, 0, 2}, {0, 2, 1, 0}, {0, 1, 2, 0}});

string q6 = "Education Policy:\na) Support for school choice and vouchers\nb) "
            "Advocate for increased funding for public education\nc) Prefer a "
            "fully publicly-funded education system ";
weightedQuestion w6 = weightedQuestion(q6, {{0, 1, 2, 0}, {2, 0}, {}});

string q7 = "Foreign Policy:\na) Support a more interventionist foreign "
            "policy\nb) Prefer a diplomatic and non-interventionist "
            "approach\nc) Prioritize isolationist policies";
weightedQuestion w7 =
    weightedQuestion(q7, {{2, 1, 0, 1}, {1, 1, 1, 1}, {0, 2, 2, 1}});

string q8 = "Taxation:\na) Support lower taxes across the board\nb) Advocate "
            "for a progressive tax system\nc) Prefer a wealth tax";
weightedQuestion w8 =
    weightedQuestion(q8, {{0, 2, 2, 0}, {2, 0, 0, 1}, {2, 0, 0, 2}});

string q9 = "Criminal Justice Reform:\na) Support for stricter law and order "
            "policies\nb) Advocate for criminal justice reform and "
            "rehabilitation\nc) Call for defunding the police";
weightedQuestion w9 =
    weightedQuestion(q9, {{0, 2, 0, 0}, {2, 1, 1, 1}, {2, 0, 0, 1}});

string q10 =
    "National Security:\na) Prioritize a strong military and defense "
    "spending\nb) Advocate for diplomatic solutions over military "
    "intervention\nc) Support disarmament and reduced military spending";
weightedQuestion w10 =
    weightedQuestion(q10, {{2, 2, 1, 0}, {1, 1, 1, 1}, {1, 0, 1, 1}});

string q11 =
    "Social Equality:\na) Support policies promoting social equality\nb) "
    "Advocate for equal opportunities but not necessarily outcomes\nc) Believe "
    "equality should be achieved through individual efforts";
weightedQuestion w11 =
    weightedQuestion(q11, {{2, 1, 0, 2}, {1, 2, 2, 1}, {0, 2, 2, 1}});

string q12 = "Trade Policy:\na) Support protectionist trade policies\nb) "
             "Advocate for free trade agreements\nc) Prefer a balanced "
             "approach with protections for domestic industries";
weightedQuestion w12 =
    weightedQuestion(q12, {{0, 2, 0, 0}, {2, 1, 2, 1}, {1, 1, 0, 1}});

string q13 = "LGBTQ+ Rights:\na) Advocate for comprehensive LGBTQ+ rights\nb) "
             "Support basic rights but with some reservations\nc) Oppose "
             "certain LGBTQ+ rights based on personal or religious beliefs";
weightedQuestion w13 =
    weightedQuestion(q13, {{2, 0, 1, 2}, {0, 1, 1, 0}, {0, 2, 0, 0}});

string q14 =
    "National Debt:\na) Prioritize reducing the national debt\nb) Balance "
    "between reducing debt and investing in social programs\nc) Support "
    "increased spending even if it contributes to the national debt";
weightedQuestion w14 =
    weightedQuestion(q14, {{0, 2, 1, 0}, {1, 0, 1, 1}, {2, 0, 0, 1}});

string q15 =
    "Voting Rights:\na) Support measures to enhance voting accessibility\nb) "
    "Advocate for stricter voting regulations to prevent fraud\nc) Believe the "
    "current voting system is sufficient";
weightedQuestion w15 =
    weightedQuestion(q15, {{2, 0, 0, 2}, {0, 2, 1, 0}, {1, 0, 1, 1}});

string q16 = "Infrastructure Spending:\na) Support increased government "
             "spending on infrastructure\nb) Advocate for private sector "
             "involvement in infrastructure projects\nc) Prefer reduced "
             "government spending on infrastructure";
weightedQuestion w16 =
    weightedQuestion(q16, {{2, 1, 0, 2}, {1, 2, 2, 1}, {0, 2, 2, 0}});

string q17 =
    "Racial Equity:\na) Support policies addressing systemic racism\nb) "
    "Acknowledge racial disparities and prefer colorblind policies\nc) Believe "
    "racial disparities are largely due to individual choices";
weightedQuestion w17 =
    weightedQuestion(q17, {{2, 0, 0, 2}, {1, 2, 1, 1}, {0, 1, 2, 0}});

string q18 =
    "Social Security:\na) Support maintaining or expanding Social Security\nb) "
    "Advocate for a partial privatization of Social Security\nc) Prefer "
    "phasing out Social Security in favor of individual retirement accounts";
weightedQuestion w18 =
    weightedQuestion(q18, {{2, 1, 0, 2}, {1, 2, 1, 1}, {0, 2, 2, 0}});

string q19 =
    "Drug Policy:\na) Support the legalization of recreational drugs\nb) "
    "Advocate for medical marijuana but with restrictions\nc) Oppose the "
    "legalization of most recreational drugs";
weightedQuestion w19 =
    weightedQuestion(q19, {{2, 0, 2, 2}, {1, 2, 1, 1}, {0, 1, 0, 0}});

string q20 = "Campaign Finance Reform:\na) Support stricter campaign finance "
             "regulations\nb) Advocate for transparency but with limited "
             "restrictions\nc) Believe in minimal government intervention in "
             "campaign financing";
weightedQuestion w20 =
    weightedQuestion(q20, {{1, 1, 1, 2}, {2, 2, 1, 1}, {1, 1, 2, 0}});

string q21 = "Affirmative Action:\na) Support affirmative action policies\nb) "
             "Advocate for a race-neutral approach to admissions and "
             "hiring\nc) Oppose affirmative action based on meritocracy";
weightedQuestion w21 =
    weightedQuestion(q21, {{2, 0, 0, 2}, {1, 2, 2, 1}, {0, 2, 2, 0}});

string q22 = "Nuclear Energy:\na) Support increased investment in nuclear "
             "energy\nb) Advocate for a focus on renewable energy sources\nc) "
             "Prefer reducing reliance on both nuclear and fossil fuels";
weightedQuestion w22 =
    weightedQuestion(q22, {{2, 1, 0, 2}, {1, 2, 2, 1}, {0, 2, 2, 0}});

string q23 = "Privacy Rights:\na) Prioritize national security over individual "
             "privacy\nb) Advocate for a balance between security and "
             "privacy\nc) Support strong privacy protections even at the "
             "expense of some security measures";
weightedQuestion w23 =
    weightedQuestion(q23, {{1, 2, 0, 0}, {1, 1, 1, 1}, {1, 0, 2, 2}});

string q24 = "Electoral College:\na) Support the current Electoral College "
             "system\nb) Advocate for a popular vote system\nc) Prefer an "
             "alternative proportional representation system";
weightedQuestion w24 =
    weightedQuestion(q24, {{1, 2, 1, 0}, {1, 0, 1, 2}, {1, 0, 1, 1}});

string q25 = "Role of Government:\na) Support a limited government with "
             "minimal intervention\nb) Advocate for a balance between "
             "government and individual freedoms\nc) Prefer a more active "
             "government role in addressing societal issues";
weightedQuestion w25 =
    weightedQuestion(q25, {{0, 2, 2, 0}, {1, 1, 0, 1}, {2, 0, -1, 2}});

string q26 =
    "Supreme Court Nominations:\na) Support the appointment of justices with "
    "conservative ideologies\nb) Advocate for moderate and centrist "
    "justices\nc) Prefer justices with progressive ideologies";
weightedQuestion w26 =
    weightedQuestion(q26, {{0, 2, 0, 0}, {1, 1, 1, 1}, {2, 0, 0, 2}});

string q27 =
    "Social Media Regulation:\na) Support stricter regulations on social media "
    "platforms\nb) Advocate for self-regulation within the tech industry\nc) "
    "Oppose government intervention in social media";
weightedQuestion w27 =
    weightedQuestion(q27, {{1, 1, 0, 1}, {1, 2, 2, 1}, {0, 1, 2, 0}});

vector<weightedQuestion> qAndScores = {w1, w2, w3, w4, w5, w6, w7, w8, w9, w10,w11, w12, w13, w14, w15, w16, w17, w18, w19, w20, w21, w22, w23, w24, w25, w26, w27}; 

vector<string> questionList = {q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27};

