--------------------------------------------------------------------------------
-- Up
--------------------------------------------------------------------------------

INSERT INTO Users(username, password, profile, volCoins)
  VALUES
    ('alice', '1234', '', 100),
    ('bob', 'test', '', 100),
    ('charlie', 'qwerty', '', 100), 
    ('attacker', 'evil', '', 0);

--------------------------------------------------------------------------------
-- Down
--------------------------------------------------------------------------------

DELETE FROM Users;
