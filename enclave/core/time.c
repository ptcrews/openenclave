// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <openenclave/internal/calls.h>
#include <openenclave/internal/time.h>

int oe_sleep(uint64_t milliseconds)
{
    int ret = -1;

    if (oe_ocall(OE_OCALL_SLEEP, milliseconds, NULL) != OE_OK)
        goto done;

    ret = 0;

done:

    return ret;
}

uint64_t oe_get_time(void)
{
    uint64_t ret = (uint64_t)-1;

    if (oe_ocall(OE_OCALL_GET_TIME, 0, &ret) != OE_OK)
    {
        ret = (uint32_t)-1;
        goto done;
    }

done:

    return ret;
}
