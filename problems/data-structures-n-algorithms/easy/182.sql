// 182. Duplicate Emails
// https://leetcode.com/problems/duplicate-emails/

SELECT Email FROM Person WHERE (select COUNT(Email) FROM Person) GROUP BY Email HAVING COUNT(Email) > 1;
