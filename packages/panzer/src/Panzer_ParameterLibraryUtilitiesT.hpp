#ifndef PANZER_PARAMETER_LIBRARY_UTILITIES_T_HPP
#define PANZER_PARAMETER_LIBRARY_UTILITIES_T_HPP

namespace panzer {

  template<typename EvaluationType>
  Teuchos::RCP<panzer::ScalarParameterEntry<EvaluationType> >
  createAndRegisterScalarParameter(const std::string name, 
				   panzer::ParamLib& pl)
  {
    if (!pl.isParameter(name))
      pl.addParameterFamily(name,true,false);
    
    Teuchos::RCP<panzer::ScalarParameterEntry<EvaluationType> > entry;
    
    if (pl.isParameterForType<EvaluationType>(name)) {
      Teuchos::RCP<Sacado::ScalarParameterEntry<EvaluationType,panzer::EvaluationTraits> > sacado_entry =
	pl.getEntry<EvaluationType>(name);
      entry = Teuchos::rcp_dynamic_cast<panzer::ScalarParameterEntry<EvaluationType> >(sacado_entry);
    }
    else {
      entry = Teuchos::rcp(new panzer::ScalarParameterEntry<EvaluationType>);
      pl.addEntry<EvaluationType>(name,entry);
    }

    return entry;
  }

}

#endif
