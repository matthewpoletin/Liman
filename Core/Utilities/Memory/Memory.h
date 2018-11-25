/**
 * @file Memory.h
 * @author matthewpoletin
 */

#pragma once

#ifndef NEW
#define NEW new
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(ELEMENT) if(ELEMENT) delete(ELEMENT); ELEMENT = NULL;
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ELEMENT) if(ELEMENT) delete [] ELEMENT; ELEMENT = NULL;
#endif