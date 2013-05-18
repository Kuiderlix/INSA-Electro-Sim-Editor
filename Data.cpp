#include "Data.h"

#include "parser.h"

Data::Data()
{
}

Data::Data(Parser *p)
{
    p->parse(this);
}
