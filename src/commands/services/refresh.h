/*---------------------------------------------------------------------------*\
                          ____  _ _ __ _ __  ___ _ _
                         |_ / || | '_ \ '_ \/ -_) '_|
                         /__|\_, | .__/ .__/\___|_|
                             |__/|_|  |_|
\*---------------------------------------------------------------------------*/
#ifndef ZYPPER_COMMANDS_SERVICES_REFRESH_H_INCLUDED
#define ZYPPER_COMMANDS_SERVICES_REFRESH_H_INCLUDED

#include "commands/basecommand.h"
#include "utils/flags/zyppflags.h"

#include <zypp/base/Flags.h>

class RefreshServicesCmd : public ZypperBaseCommand
{

public:
  RefreshServicesCmd ( const std::vector<std::string> &commandAliases_r );

  int refreshServices ( Zypper &zypper );

  void setForce(bool force);
  void setWithRepos(bool withRepos);
  void setRestoreStatus(bool restoreStatus);

  // ZypperBaseCommand interface
protected:
  std::vector<BaseCommandConditionPtr> conditions() const override;
  zypp::ZyppFlags::CommandGroup cmdOptions() const override;
  void doReset() override;
  int execute(Zypper &zypper, const std::vector<std::string> &positionalArgs) override;
  int systemSetup(Zypper &zypp_r) override;

private:
  bool _force = false;
  bool _withRepos = false;
  bool _restoreStatus = false;
};

#endif
