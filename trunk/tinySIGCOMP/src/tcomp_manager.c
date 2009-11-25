/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tcomp_manager.c
 * @brief  SigComp Manager.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tcomp_manager.h"
#include "tsk_debug.h"

#include "tcomp_compressordisp.h"
#include "tcomp_decompressordisp.h"
#include "tcomp_statehandler.h"

#include "tsk_object.h"
#include "tsk_safeobj.h"

#define MAX_DMS	131072
#define MAX_SMS	131072
#define MAX_CPB	128

/**@defgroup tcomp_manager_group SIGCOMP manager.
* SigComp manager.
*/

typedef struct tcomp_manager_s
{
	TSK_DECLARE_OBJECT;
	
	tcomp_compressordisp_t *dispatcher_compressor;
	tcomp_decompressordisp_t *dispatcher_decompressor;
	tcomp_statehandler_t *stateHandler;
	
	TSK_DECLARE_SAFEOBJ;
}
tcomp_manager_t;

/**@ingroup tcomp_manager_group
*/
size_t tcomp_manager_compress(tcomp_manager_handle_t *handle, uint64_t compartmentId, const void* input_ptr, size_t input_size, void* output_ptr, size_t output_size, int stream)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return 0;
	}

	return 0;
}

/**@ingroup tcomp_manager_group
*/
size_t tcomp_manager_decompress(tcomp_manager_handle_t *handle, const void* input_ptr, size_t input_size, tcomp_result_t *lpResult)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return 0;
	}

	return 0;
}

/**@ingroup tcomp_manager_group
*/
size_t tcomp_manager_getNextMessage(tcomp_manager_handle_t *handle, tcomp_result_t *lpResult)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return 0;
	}

	return 0;
}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_provideCompartmentId(tcomp_manager_handle_t *handle, tcomp_result_t *lpResult)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}


}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_closeCompartment(tcomp_manager_handle_t *handle, uint64_t compartmentId)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}


}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_setDecompression_Memory_Size(tcomp_manager_handle_t *handle, uint32_t dms)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}
	
	tcomp_params_setDmsValue(manager->stateHandler->sigcomp_parameters, (dms > MAX_DMS ? MAX_DMS : dms));
}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_setState_Memory_Size(tcomp_manager_handle_t *handle, uint32_t sms)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}

	tcomp_params_setSmsValue(manager->stateHandler->sigcomp_parameters, (sms > MAX_SMS ? MAX_SMS : sms));
}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_setCycles_Per_Bit(tcomp_manager_handle_t *handle, uint8_t cpb)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}

	tcomp_params_setCpbValue(manager->stateHandler->sigcomp_parameters, (cpb > MAX_CPB ? MAX_CPB : cpb));
}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_setSigComp_Version(tcomp_manager_handle_t *handle, uint8_t version)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}

	manager->stateHandler->sigcomp_parameters->SigComp_version = version;
}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_addCompressor(tcomp_manager_handle_t *handle/*, SigCompCompressor* compressor*/)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}


}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_addSipSdpDictionary(tcomp_manager_handle_t *handle)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}


}

/**@ingroup tcomp_manager_group
*/
void tcomp_manager_addPresenceDictionary(tcomp_manager_handle_t *handle)
{
	tcomp_manager_t *manager = handle;
	if(!manager)
	{
		TSK_DEBUG_ERROR("NULL sigcomp manager.");
		return;
	}


}














//========================================================
//	SigComp manager object definition
//

/**@ingroup tcomp_manager_group
*/
static void* tcomp_manager_create(void * self, va_list * app)
{
	tcomp_manager_t *manager = self;
	if(manager)
	{
		manager->stateHandler = TCOMP_STATEHANDLER_CREATE();
		manager->dispatcher_compressor = TCOMP_COMPRESSORDISP_CREATE(manager->stateHandler);
		manager->dispatcher_decompressor = TCOMP_DECOMPRESSORDISP_CREATE(manager->stateHandler);

		/* Initialize safeobject */
		tsk_safeobj_init(manager);
	}
	else
	{
		TSK_DEBUG_ERROR("Failed to create new manager.");
	}

	return self;
}

/**@ingroup tcomp_manager_group
*/
static void* tcomp_manager_destroy(void *self)
{
	tcomp_manager_t *manager = self;
	if(manager)
	{
		/* Deinitialize safeobject */
		tsk_safeobj_deinit(manager);
		
		TCOMP_DECOMPRESSORDISP_SAFE_FREE(manager->dispatcher_decompressor);
		TCOMP_COMPRESSORDISP_SAFE_FREE(manager->dispatcher_compressor);
		TCOMP_STATEHANDLER_SAFE_FREE(manager->stateHandler);
	}
	else TSK_DEBUG_ERROR("Null manager.");
	
	return self;
}

static const tsk_object_def_t tcomp_manager_def_s = 
{
	sizeof(tcomp_manager_t),
	tcomp_manager_create,
	tcomp_manager_destroy,
	0,
	0,
	0
};
const void *tcomp_manager_def_t = &tcomp_manager_def_s;