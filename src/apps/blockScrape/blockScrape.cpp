/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *------------------------------------------------------------------------*/
#include "etherlib.h"
#include "options.h"

//----------------------------------------------------------------------------------
int main(int argc, const char *argv[]) {

    etherlib_init("local");

    COptions options;
    if (!options.prepareArguments(argc, argv))
        return 0;

    string_q command = nextTokenClear(options.commandList, '\n');
    if (!options.parseArguments(command))
        return 0;

    cout << bGreen << "Scraping new blocks..." << "\n" << cOff;
    if (!freshenLocalCache(options))
        cout << "\tThe tool ended with an error.";
    cout << bGreen << "...done\n" << cOff;

    etherlib_cleanup();

    return 0;
}
