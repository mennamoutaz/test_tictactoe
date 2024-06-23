#include "test_mainwindow.h"
#include "mainwindow.h"

#include <QtTest/QTest>


void Tests::testHashPassword()
{
    QCOMPARE(hashPassword("password123"), std::string("1800612796"));
    QCOMPARE(hashPassword("qwerty"), std::string("806243782"));
    QCOMPARE(hashPassword("abc123"), std::string("864586122"));
}

void Tests::testTimeToString()
{
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(0);
    QCOMPARE(timeToString(timePoint), std::string("1970-01-01 00:00:00"));

    timePoint = std::chrono::system_clock::from_time_t(1609459200); // 2021-01-01 00:00:00
    QCOMPARE(timeToString(timePoint), std::string("2021-01-01 00:00:00"));
}

void Tests::testSignup()
{
    sqlite3* db;
    sqlite3_open(":memory:", &db); // Open an in-memory database

    std::string result = signup(db, "test@example.com", "password123", "Test User", 30, "Test City");
    QCOMPARE(result, std::string("test@example.com"));

    sqlite3_close(db);
}

void Tests::testLogin()
{
    sqlite3* db;
    sqlite3_open(":memory:", &db); // Open an in-memory database

    signup(db, "test@example.com", "password123", "Test User", 30, "Test City");

    std::string result = login(db, "test@example.com", "password123");
    QCOMPARE(result, std::string("test@example.com"));

    sqlite3_close(db);
}

QTEST_MAIN(Tests)
#include "test_mainwindow.moc"
