*** Settings ***
Documentation    Practice with Robot Framework libraries

Library    Collections
Library    String

*** Test Cases ***
User Data Validation
    ${users}=    Create List    teemu    alice    bob
    List Should Contain Value    ${users}    alice
    List Should Contain Value    ${users}    bob

    ${uppercase_username}=    Convert To Upper Case    teemu
    Should Be Equal    ${uppercase_username}    TEEMU